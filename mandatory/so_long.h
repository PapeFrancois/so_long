/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:42:54 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/13 12:15:41 by hepompid         ###   ########.fr       */
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

typedef struct s_img {
	void	*empty;
	void	*wall;
	void	*player;
	void	*coin;
	void	*exit;
	void	*exit2;
	void	*ennemy;
}	t_img;

typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	char	**map;
	t_img	img;
	int		exit;
	int		nofmovements;
}	t_game;

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

int		strlen_wo_newline(char *str);
char	*strcpy_wo_newline(char *dst, const char *src);
char	**file_manager(char *arg, char **map);
int		parsing_manager(char **map);
int		valid_path_checker(char **map);
void	malloc_failure(char **map, int i, int fd, char *str);
void	free_table(char **table);
void	game_manager(char **map);
void	map_dimension_finder(char **map, int *i, int *j);
t_img	img_creator(t_game game);
void	print_map(t_game game, t_img img);
t_game	event_manager(t_game game, t_img img);
t_game	*up(t_game *game);
t_game	*down(t_game *game);
t_game	*right(t_game *game);
t_game	*left(t_game *game);
int		collectible_left(char **map);
int		close_window(t_game *game);

#endif