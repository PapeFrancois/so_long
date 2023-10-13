/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:22:29 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/13 11:42:31 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(char **map, int *i, int *j)
{
	*i = 0;
	while (map[*i])
	{
		*j = 0;
		while (map[*i][*j])
		{
			if (map[*i][*j] == 'P')
				return ;
			(*j)++;
		}
		(*i)++;
	}
}

t_game	*up(t_game *game)
{
	int	i;
	int	j;

	find_player(game->map, &i, &j);
	if (game->map[i - 1][j] == '1')
		return (game);
	game->nofmovements++;
	ft_printf("\r%d", game->nofmovements);
	if (game->exit == 1)
	{
		game->exit = 0;
		game->map[i][j] = 'E';
	}
	else
	{
		if (game->map[i - 1][j] == 'E')
			game->exit = 1;
		if (game->map[i - 1][j] == 'Y')
			close_window(game);
		if (game->map[i - 1][j] == 'F')
			close_window(game);
		game->map[i][j] = '0';
	}
	game->map[i - 1][j] = 'P';
	return (game);
}

t_game	*down(t_game *game)
{
	int	i;
	int	j;

	find_player(game->map, &i, &j);
	if (game->map[i + 1][j] == '1')
		return (game);
	game->nofmovements++;
	ft_printf("\r%d", game->nofmovements);
	if (game->exit == 1)
	{
		game->exit = 0;
		game->map[i][j] = 'E';
	}
	else
	{
		if (game->map[i + 1][j] == 'E')
			game->exit = 1;
		if (game->map[i + 1][j] == 'Y')
			close_window(game);
		if (game->map[i + 1][j] == 'F')
			close_window(game);
		game->map[i][j] = '0';
	}
	game->map[i + 1][j] = 'P';
	return (game);
}

t_game	*left(t_game *game)
{
	int	i;
	int	j;

	find_player(game->map, &i, &j);
	if (game->map[i][j - 1] == '1')
		return (game);
	game->nofmovements++;
	ft_printf("\r%d", game->nofmovements);
	if (game->exit == 1)
	{
		game->exit = 0;
		game->map[i][j] = 'E';
	}
	else
	{
		if (game->map[i][j - 1] == 'E')
			game->exit = 1;
		if (game->map[i][j - 1] == 'Y')
			close_window(game);
		if (game->map[i][j - 1] == 'F')
			close_window(game);
		game->map[i][j] = '0';
	}
	game->map[i][j - 1] = 'P';
	return (game);
}

t_game	*right(t_game *game)
{
	int	i;
	int	j;

	find_player(game->map, &i, &j);
	if (game->map[i][j + 1] == '1')
		return (game);
	game->nofmovements++;
	ft_printf("\r%d", game->nofmovements);
	if (game->exit == 1)
	{
		game->exit = 0;
		game->map[i][j] = 'E';
	}
	else
	{
		if (game->map[i][j + 1] == 'E')
			game->exit = 1;
		if (game->map[i][j + 1] == 'Y')
			close_window(game);
		if (game->map[i][j + 1] == 'F')
			close_window(game);
		game->map[i][j] = '0';
	}
	game->map[i][j + 1] = 'P';
	return (game);
}
