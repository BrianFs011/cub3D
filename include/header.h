/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:44:50 by briferre          #+#    #+#             */
/*   Updated: 2023/06/28 14:51:36 by briferre         ###   ########.fr       */
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

typedef struct s_camera
{
	double	modulo_cam;
	double	x;
	double	y;
	double	z;
	double	looking_x;
	double	looking_y;
	double	looking_z;
	double	phi;
	double	theta;
}t_camera;

typedef struct s_points
{
	double	x;
	double	y;
	double	z;
}t_points;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_camera	camera;
	t_data		img;
	char		**map;
	int			map_size;
}t_mlx;


//------ MATHS ------
double	degrees_to_radians(double degree);

//------ FT_UTILS ------
//ft_utils.c
int		ternary_int(int condition, int a, int b);

//------ MAP ------
void	map_load(t_mlx *mlx);

//------ DRAWS ------
//draw_rectangle
void	load_background(t_data *data, int color);
void	draw_rect(t_data *data, int *p, int color);

void	draw_line(t_data *data, int *p, int color);
void	draw_objects(t_mlx *mlx);

//primitives.c
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	screen_clear(t_data *data, int color);

//camera.c
void	cam_init(t_mlx *mlx);

//------ EVENTOS ------
//keyboard
int		handle_key_press(int keycode, t_mlx *mlx);


//------ MINILIBX ------
//window.c
void	window_init(t_mlx *mlx);
//image.c
void	image_init(t_mlx *mlx);

#endif