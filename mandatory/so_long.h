/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:42:54 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/12 10:37:01 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

int		strlen_wo_newline(char *str);
char	*strcpy_wo_newline(char *dst, const char *src);
char	**file_manager(char *arg, char **map);
int		parsing_manager(char **map);
void	graphic();

#endif