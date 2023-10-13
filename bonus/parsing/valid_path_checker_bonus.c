/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_checker_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:05:56 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/13 12:30:21 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	max(char **map, int trigger_i)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (trigger_i == 1)
	{
		while (map[i])
			i++;
		return (i - 1);
	}
	while (map[0][j])
		j++;
	return (j - 1);
}

// calcule soit i max soit j max
// si trigger_i == 1, on calcule i max, sinon j max

void	valid_path_finder(char **map, int i, int j)
{
	map[i][j] = 'V';
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'V'
		&& map[i][j + 1] != 'F' && j < max(map, 0))
		valid_path_finder(map, i, j + 1);
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'V'
		&& map[i + 1][j] != 'F' && i < max(map, 1))
		valid_path_finder(map, i + 1, j);
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'V'
		&& map[i][j - 1] != 'F' && j > 0)
		valid_path_finder(map, i, j - 1);
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'V'
		&& map[i - 1][j] != 'F' && i > 0)
		valid_path_finder(map, i - 1, j);
}

int	all_visited_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**duplicate_map(char **map)
{
	char	**temp_map;
	int		i;

	i = 0;
	while (map[i])
		i++;
	temp_map = malloc((i + 1) * sizeof (char *));
	if (!temp_map)
	{
		free_table(map);
		exit(0);
	}
	i = 0;
	while (map[i])
	{
		temp_map[i] = ft_strdup(map[i]);
		if (!temp_map[i])
		{
			free_table(map);
			malloc_failure(temp_map, i - 1, -1, NULL);
		}
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}

int	valid_path_checker(char **map)
{
	int		i;
	int		j;
	char	**temp_map;

	temp_map = duplicate_map(map);
	i = 0;
	while (temp_map[i])
	{
		j = 0;
		while (temp_map[i][j])
		{
			if (temp_map[i][j] == 'P')
				valid_path_finder(temp_map, i, j);
			j++;
		}
		i++;
	}
	if (all_visited_checker(temp_map) == 1)
	{
		free_table(temp_map);
		return (1);
	}
	free_table(temp_map);
	return (0);
}
