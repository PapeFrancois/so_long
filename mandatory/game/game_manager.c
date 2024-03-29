/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:55:14 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/13 14:30:35 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_manager(char **map)
{
	t_game	game;
	t_img	img;

	game.map = map;
	game.exit = 0;
	game.nofmovements = 0;
	game.mlx = mlx_init();
	map_dimension_finder(map, &game.y, &game.x);
	if (game.x > 1920 || game.y > 1080)
	{
		ft_printf("error: the map is too big\n");
		return ;
	}
	game.mlx_win = mlx_new_window(game.mlx, game.x, game.y, "so_long");
	img = img_creator(game);
	print_map(game, img);
	ft_printf("%d", game.nofmovements);
	game = event_manager(game, img);
	mlx_loop(game.mlx);
}
