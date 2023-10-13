/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:32:37 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/13 12:23:34 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.exit2);
	mlx_destroy_image(game->mlx, game->img.empty);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.ennemy);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_table(game->map);
	exit(0);
}

int	collectible_left(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	open_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				map[i][j] = 'Y';
			j++;
		}
		i++;
	}
}

int	keypress(int keycode, t_game *game)
{
	char	*str;

	if (keycode == ESC)
		close_window(game);
	if (keycode == RIGHT)
		game = right(game);
	if (keycode == LEFT)
		game = left(game);
	if (keycode == UP)
		game = up(game);
	if (keycode == DOWN)
		game = down(game);
	if (collectible_left(game->map) == 0)
		open_exit(game->map);
	print_map(*game, game->img);
	str = ft_itoa(game->nofmovements);
	if (str)
	{
		mlx_string_put(game->mlx, game->mlx_win, 10, 15, 0x0FAE1, str);
		free(str);
	}
	return (0);
}

t_game	event_manager(t_game game, t_img img)
{
	game.img = img;
	mlx_hook(game.mlx_win, 17, 0L, &close_window, &game);
	mlx_hook(game.mlx_win, 2, 1L << 0, &keypress, &game);
	return (game);
}
