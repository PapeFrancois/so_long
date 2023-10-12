/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   berfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:58:21 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/12 10:48:33 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_check(char *a)
{
	int	i;

	i = ft_strlen(a);
	if (i <= 4)
		return (1);
	i--;
	if (a[i] != 'r' || a[i - 1] != 'e' || a[i - 2] != 'b' || a[i - 3] != '.')
	{
		ft_printf("error: the map must have the .ber extention\n");
		return (1);
	}
	return (0);
}

char	**map_creator(int fd, char **map)
{
	int		nofline;
	char	*str;

	nofline = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		nofline++;
		str = get_next_line(fd);
	}
	if (nofline > 0)
		map = malloc((nofline + 1) * sizeof(char *));
	else
		ft_printf("error: the map is empty\n");
	return (map);
}

void	malloc_failure(char **map, int i, int fd, char *str)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	free(str);
	close(fd);
	exit(0);
}

char	**fill_map(int fd, char **map)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		map[i] = malloc((strlen_wo_newline(str) + 1) * sizeof(char));
		if (!map[i])
			malloc_failure(map, i - 1, fd, str);
		map[i] = strcpy_wo_newline(map[i], str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**file_manager(char *arg, char **map)
{
	int		fd;

	if (ber_check(arg) == 1)
		return (NULL);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (NULL);
	}
	map = map_creator(fd, map);
	close(fd);
	if (!map)
		return (NULL);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		return (NULL);
	}
	map = fill_map(fd, map);
	close (fd);
	return (map);
}
