/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:41:50 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/15 11:58:38 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include "get_next_line.h"

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->
	
}

int	main()
{
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	int		img_width;
	int		img_height;

	img_width = 64;
	img_height = 64;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img1 = mlx_xpm_file_to_image(mlx, "./images/resized_tile2.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/resized_hero2.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/resized_coin2.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/resized_wall2.xpm", &img_width, &img_height);
	// img2 = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	// img3 = mlx_xpm_file_to_image(mlx, "./images/hero.xpm", &img_width, &img_height);
	// img4 = mlx_xpm_file_to_image(mlx, "./images/coin.xpm", &img_width, &img_height);
	// img5 = mlx_xpm_file_to_image(mlx, "./images/door.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img1, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 0, 0);
	mlx_put_image_to_window(mlx, win, img3, 0, 64);
	mlx_put_image_to_window(mlx, win, img4, 64, 64);
	// mlx_put_image_to_window(mlx, win, img2, 64, 0);
	// mlx_put_image_to_window(mlx, win, img3, 128, 0);
	// mlx_put_image_to_window(mlx, win, img4, 0, 64);
	// mlx_put_image_to_window(mlx, win, img5, 64, 64);
	mlx_loop(mlx);
	return (0);
}