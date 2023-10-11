/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:48:22 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/11 13:44:17 by hepompid         ###   ########.fr       */
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
	map = file_manager(argv[1]);

	// int i = 0;
	// while (map[i])
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }

	if (map)
		free_table(map);
	return (0);
}
