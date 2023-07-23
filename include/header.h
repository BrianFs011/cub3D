/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:44:50 by briferre          #+#    #+#             */
/*   Updated: 2023/07/23 02:22:58 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"
# include "libft.h"

# define HEIGHT 600
# define WIDTH 600
# define X 0
# define Y 1
# define Z 2
# define PI 3.14159265

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

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_camera	camera;
	t_data		img;
	char		**map;
	int			map_size;
	int			unlook;
	int			radius;
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

//------ MAP ------
void		map_load(t_mlx *mlx, char **argv);
void		clear_memory_map(t_mlx *mlx);

//------ DRAWS ------
//draw_rectangle.c
void		load_background(t_data *data);
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