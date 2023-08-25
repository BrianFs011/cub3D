void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	// while (mlx->map[++i] && i < 5)
	while (mlx->map[++i])
	{
		j = -1;
		// while (mlx->map[++j] && j < 1)
		while (mlx->map[++j])
			if (mlx->map[j][i] == '1')
				draw_rect(&mlx->img, vector_points(i * 100,
						j * 100, 0, 0),
					create_trgb(0, 255, 0, 0));
	}
}

double	find_wall(t_mlx *mlx)
{
	double	x[2];
	double	y[2];
	double	radius;

	x[0] = ternary_d(cos(degrees_to_radians(mlx->camera.theta)) < 0, -mlx->radius, mlx->radius) + mlx->camera.position.x + 2 * cos(degrees_to_radians(mlx->camera.theta));
	y[0] = ternary_d(sin(degrees_to_radians(mlx->camera.theta)) < 0, -mlx->radius, mlx->radius) + mlx->camera.position.y + 2 * sin(degrees_to_radians(mlx->camera.theta));
	x[1] = mlx->camera.position.x;
	y[1] = mlx->camera.position.y;
	// printf("(%d, %d) %lf %lf %lf %lf\n", (int)(y[0] / 100), (int)(x[0] / 100), x[0], y[0], x[1], y[1]);
	while (mlx->map[(int)(y[0] / 100)][(int)(x[0] / 100)] != '1')
	{
		x[1] += 2 * cos(degrees_to_radians(mlx->camera.theta));
		y[1] += 2 * sin(degrees_to_radians(mlx->camera.theta));
		x[0] = ternary_d(cos(degrees_to_radians(mlx->camera.theta)) < 0, -mlx->radius, mlx->radius) + x[1] + 2 * cos(degrees_to_radians(mlx->camera.theta));
		y[0] = ternary_d(sin(degrees_to_radians(mlx->camera.theta)) < 0, -mlx->radius, mlx->radius) + y[1] + 2 * sin(degrees_to_radians(mlx->camera.theta));
	}
	radius = sqrt(pow(x[1] - mlx->camera.position.x, 2) + pow(y[1] - mlx->camera.position.y, 2));
	return (radius);
}

void	draw_direction(t_mlx *mlx, int *p, int color)
{
	draw_line(&mlx->img, vector_points(
			p[X],
			p[X] + (find_wall(mlx) + mlx->radius) * cos(degrees_to_radians(mlx->camera.theta)),
			p[Y],
			p[Y] + (find_wall(mlx) + mlx->radius) * sin(degrees_to_radians(mlx->camera.theta))),
		color);
	free(p);
}

void	draw_objects(t_mlx *mlx)
{
	draw_map(mlx);
	draw_circle(&mlx->img,
		vector_points(mlx->camera.position.x, mlx->camera.position.y, 0, 0), mlx->radius,
		create_trgb(0, 0, 255, 0));
	draw_direction(mlx,
		vector_points(mlx->camera.position.x, mlx->camera.position.y, 0, 0),
		create_trgb(0, 0, 0, 255));
}

int	old_render(t_mlx *mlx)
{
	if (mlx->unlook)
	{
		draw_objects(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
		mlx->unlook = 0;
	}
	return (0);
}