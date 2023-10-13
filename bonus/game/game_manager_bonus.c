/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:55:14 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/13 12:29:57 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	game_manager(char **map)
{
	t_game	game;
	t_img	img;
	char	*str;

	game.map = map;
	game.exit = 0;
	game.nofmovements = 0;
	game.mlx = mlx_init();
	map_dimension_finder(map, &game.y, &game.x);
	if (game.x > 1920 || game.y > 1080)
		return ;
	game.mlx_win = mlx_new_window(game.mlx, game.x, game.y, "so_long");
	img = img_creator(game);
	print_map(game, img);
	str = ft_itoa(game.nofmovements);
	if (str)
	{
		mlx_string_put(game.mlx, game.mlx_win, 10, 15, 0x0FAE1, str);
		free(str);
	}
	game = event_manager(game, img);
	mlx_loop(game.mlx);
}
