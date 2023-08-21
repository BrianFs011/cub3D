/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:44:50 by briferre          #+#    #+#             */
/*   Updated: 2023/08/21 03:19:03 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>
# include "get_next_line.h"
# include "libft.h"

# define HEIGHT 600
# define WIDTH 600
# define X 0
# define Y 1
# define Z 2
# define PI 3.14159265
# define TRUE 1
# define FALSE 0
# define ARGUMENT_ERROR "Error\nInvalid quantity of arguments. \
							Correct usage: ./cub3D <map_address>"
# define FD_ERROR "Error\nAn error occured when opening .cub file"
# define FILE_TYPE_ERROR "Error\nInvalid type of map file. Map file must be .cub"
# define MAP_CONFIG_ERROR "Error\nInvalid configuration of map. \
							Map must be surrounded by walls"
# define PLAYER_ERROR "Error\nInvalid quantity of Players. Map must have one \
						player represented by N, S, E or W"
# define CHAR_ERROR "Error\nInvalid character in Map."
# define MAP_STYLE_ERROR "Error\nInvalid configuration of map style."

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_ipoints
{
	int	x;
	int	y;
	int	x1;
	int	y1;
}t_ipoints;

typedef struct s_points
{
	double	x;
	double	y;
	double	x1;
	double	y1;
}t_points;

typedef struct s_camera
{
	t_points	position;
	t_points	direction;
	t_points	plane;
	t_points	pixel;
	t_points	ray_dir;
	t_points	delta_dist;
	t_points	dist_to_side;
	t_ipoints	map_pos;
	t_ipoints	wall_map_pos;
	t_points	dda_line_size;
	int			hit_side;
	double		perpendicular_dist;
	double		modulo_cam;
	double		phi;
	double		theta;
}t_camera;

typedef struct s_error
{
	int		type;
	char	*error_message;
}t_error;

typedef struct s_map
{
	char		**matrix;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	int			color_floor;
	int			color_ceil;
	int			size;

}t_map;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			unlook;
	int			radius;
	int			map_size;
	int			map_height;
	int			map_width;
	int			line_width;
	t_map		map;
	t_camera	camera;
	t_data		img;
	t_list		*file_loaded;
	t_error		error;
}t_mlx;

//------ MATHS ------
double		degrees_to_radians(double degree);
double		ray_to_plane(double direction, double plane, double multiple);
double		ray_multiple(int i);
double		magnitude(int delta_x, int delta_y);
double		abs_d(double value);
//vectors_d
void		vector_print_d(double *v);
double		*vector_add_d(double *v1, double *v2);
double		*vector_emultiple_d(double *v1, double escalar);
double		*vector_rotate(double *v, double angle);
//vectors_i
void		vector_print_i(int *v);
//vectors_p
t_points	vector_rotate_p(t_points p, double angle);
t_points	vector_add(t_points v1, t_points v2);
t_points	vector_emultiple(t_points v, double escalar);
t_points	vector_init(double p0, double p1, double p2, double p3);

//------ FT_UTILS ------
//ft_utils.c
int			ternary_int(int condition, int a, int b);
double		ternary_d(int condition, double a, double b);
void		free_split(char **string);
void		del(void *d);
void		exit_error(char *error, t_mlx *mlx);
int			set_error_msg(t_mlx *mlx, char *error_msg);

//------ MAP ------
void		validate_args(int argc, char **argv);
int			check_map(t_mlx *mlx);
int			check_map_vertically(t_mlx *mlx);
int			get_tex_name(char **tex_name, char *string);
int			get_floor_ceil(t_mlx *mlx, char *string, int floor);
void		get_style(t_mlx *mlx);

//ft_str.c
char		*ft_strcpy(char *src, int src_free);

//free.c
void		clear_tex_name(t_mlx *mlx);

//error.c
void		set_error(t_error *error, char *msg);

//------ MAP ------
void		get_file(t_mlx *mlx, char **argv);
void		get_style(t_mlx *mlx);
void		get_map(t_mlx *mlx);
// void		map_load(t_mlx *mlx, char **argv);

//------ PERSONAGE ------
void		set_orientation(t_mlx *mlx);
t_points	find_personage(char *string, t_points cp, int i);

//------ DRAWS ------
//draw_rectangle.c
void		load_background(t_data *data, int floor, int ceil);
void		draw_rect(t_data *data, int *p, int color);

void		draw_line(t_data *data, int *p, int color);
void		draw_objects(t_mlx *mlx);

//------- DRAW UTILS --------
int			*vector_points_i(int p0, int p1, int p2, int p3);
double		*vector_points_d(double p0, double p1, double p2, double p3);

//draw_circle.c
void		draw_circle(t_data *data, int *p, int r, int color);

//primitives.c
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

//camera.c
void		cam_init(t_mlx *mlx);

//------ EVENTOS ------
//keyboard
int			handle_key_press(int keycode, t_mlx *mlx);

//------ MINILIBX ------
//window.c
void		window_init(t_mlx *mlx);
int			close_program(t_mlx *mlx);

//image.c
void		image_init(t_mlx *mlx);

//------ MINILIBX ------
//engine.c
void		engine(t_mlx *mlx);

//engine_utils.c
void		delta_dist(t_mlx *mlx);
void		dist_to_side_x(t_mlx *mlx, int step[2]);
void		dist_to_side_y(t_mlx *mlx, int step[2]);

#endif