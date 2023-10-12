/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:52:32 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/12 11:36:18 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	forbidden_char_checker(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	rectangular_checker(char **map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	wall_surrounded_checker(char **map)
{
	int	i;
	int	j;
	int	siz;
	int	len;

	i = 0;
	siz = 0;
	while (map[siz + 1])
		siz++;
	len = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == siz) && map[i][j] != '1')
				return (1);
			if (i != 0 && i != siz && (j == 0 || j == len) && map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	mandatory_char_checker(char **map, int i, int j)
{
	int	player;
	int	exit;
	int	coin;

	player = 0;
	exit = 0;
	coin = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'C')
				coin++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || coin < 1)
		return (1);
	return (0);
}

int	parsing_manager(char **map)
{
	if (forbidden_char_checker(map) == 1)
		return (1);
	if (rectangular_checker(map) == 1)
		return (1);
	if (wall_surrounded_checker(map) == 1)
		return (1);
	if (mandatory_char_checker(map, 0, 0) == 1)
		return (1);
	if (valid_path_checker(map) == 1)
		return (1);
	return (0);
}
