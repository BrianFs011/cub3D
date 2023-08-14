// for (i = 0; i < texWidth; i++)
// 	for (int j = 0; j < texHeight; j++)
// 		my_mlx_pixel_put(&mlx->img, 300 + i, 300 + j, mlx->textureWE[j][i]);
// i = 0;
// int j = 0;
// for (int x = 0; x < 300; x++)
// {
// 	// for (int y = 0; y < texWidth; y++)
// 	// {
// 	// 	my_mlx_pixel_put(&mlx->img, 300 + x, 300 + y - 64, mlx->textureWE[y][x]);
// 	// 	// draw_line(&mlx->img,
// 	// 	// 	vector_points_i(400, 400, 300, 364),
// 	// 	// 	create_trgb(0, 255, 0, 0));
// 	// }
// 	draw_line_tex(&mlx->img,
// 		vector_points_i(400 + x, 400 + x, 300, 364),
// 		mlx);
// }

// draw_line(&mlx->img,
	// 	vector_points_i(i,
	// 		i,
	// 		(HEIGHT / 2) - (wall_line_height / 2),
	// 		(HEIGHT / 2) + (wall_line_height / 2)),
	// 	create_trgb(0, mlx->camera.hit_side ? 255 : 255 / 2, 0, 0));


	// printf("%d %lf %lf\n", i,
	// 	(HEIGHT / 2) - (wall_line_height / 2),
	// 	(HEIGHT / 2) + (wall_line_height / 2));


	// draw_line_texture(&mlx->img,
	// 	vector_points_i(i,
	// 		i,
	// 		(HEIGHT / 2) - (wall_line_height / 2) >= 0 ? (HEIGHT / 2) - (wall_line_height / 2) : 0,
	// 		(HEIGHT / 2) + (wall_line_height / 2) <= HEIGHT ? (HEIGHT / 2) + (wall_line_height / 2) : HEIGHT),
	// 	mlx);