/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:48:22 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/12 10:58:40 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (0);
	map = NULL;
	map = file_manager(argv[1], map);
	if (!map)
		return (0);
	if (parsing_manager(map) == 1)
		ft_printf("error: the map's format is incorrect\n");
	else
		graphic();
	free_table(map);
	return (0);
}
