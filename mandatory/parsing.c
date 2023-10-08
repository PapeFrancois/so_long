/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:58:21 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/08 12:13:53 by hepompid         ###   ########.fr       */
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
		return (1);
	return (0);
}

int	nofline_calculator(char *arg)
{
	int		fd;
	int		nofline;
	char	*str;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit (0);
	}
}

char	**parsing(char *arg)
{
	char	**map;
	int		fd;
}
