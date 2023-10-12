/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:32:37 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/12 15:04:58 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.empty);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_table(game->map);
	exit(0);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	return (0);
}

void	event_manager(t_game game, t_img img)
{
	game.img = img;
	mlx_hook(game.mlx_win, 17, 0L, &close_window, &game);
	mlx_hook(game.mlx_win, 2, 1L<<0, &keypress, &game);
}
