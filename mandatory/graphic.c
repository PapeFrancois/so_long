/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:43:53 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/12 10:59:34 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int hello(int keycode, void *param)
{
	(void) param;
	printf("keycode = %d\n", keycode);
	return (0);
}

void	graphic()
{
	void *mlx;
	void *mlx_win;
	void	*img;
	char	*relative_path = "assets/sprite2.xpm";
	int		img_width;
	int		img_height;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 250, "caca");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_hook(mlx_win, 2, 1L<<0, &hello, NULL);
	// mlx_hook(mlx_win, 4, 1L<<2, &hello, NULL);
	mlx_hook(mlx_win, 17, 0L, &hello, NULL);
	mlx_loop(mlx);
}