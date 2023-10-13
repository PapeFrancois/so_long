/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:07:40 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/13 12:29:52 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	map_dimension_finder(char **map, int *i, int *j)
{
	*i = 0;
	while (map[*i])
		(*i)++;
	*j = 0;
	while (map[0][*j])
		(*j)++;
	(*i) *= 64;
	(*j) *= 64;
}

t_img	img_creator(t_game game)
{
	t_img	img;
	int		h;
	int		w;

	img.empty = mlx_xpm_file_to_image(game.mlx, "assets/free.xpm", &w, &h);
	img.wall = mlx_xpm_file_to_image(game.mlx, "assets/wall.xpm", &w, &h);
	img.player = mlx_xpm_file_to_image(game.mlx, "assets/sprite2.xpm", &w, &h);
	img.coin = mlx_xpm_file_to_image(game.mlx, "assets/coin.xpm", &w, &h);
	img.exit = mlx_xpm_file_to_image(game.mlx, "assets/exit.xpm", &w, &h);
	img.exit2 = mlx_xpm_file_to_image(game.mlx, "assets/exit2.xpm", &w, &h);
	img.ennemy = mlx_xpm_file_to_image(game.mlx, "assets/ennemy.xpm", &w, &h);
	return (img);
}

void	put_image(t_game g, t_img img, int i, int j)
{
	if (g.map[i][j] == '0')
		mlx_put_image_to_window(g.mlx, g.mlx_win, img.empty, j * 64, i * 64);
	if (g.map[i][j] == '1')
		mlx_put_image_to_window(g.mlx, g.mlx_win, img.wall, j * 64, i * 64);
	if (g.map[i][j] == 'P')
		mlx_put_image_to_window(g.mlx, g.mlx_win, img.player, j * 64, i * 64);
	if (g.map[i][j] == 'E')
		mlx_put_image_to_window(g.mlx, g.mlx_win, img.exit, j * 64, i * 64);
	if (g.map[i][j] == 'C')
		mlx_put_image_to_window(g.mlx, g.mlx_win, img.coin, j * 64, i * 64);
	if (g.map[i][j] == 'F')
		mlx_put_image_to_window(g.mlx, g.mlx_win, img.ennemy, j * 64, i * 64);
	if (g.map[i][j] == 'Y')
		mlx_put_image_to_window(g.mlx, g.mlx_win, img.exit2, j * 64, i * 64);
}

void	print_map(t_game game, t_img img)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			put_image(game, img, i, j);
			j++;
		}
		i++;
	}
}
