/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   berfile2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:02:54 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/13 12:30:12 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	strlen_wo_newline(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (1);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*strcpy_wo_newline(char *dst, const char *src)
{
	int	i;

	i = 0;
	if (src[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
