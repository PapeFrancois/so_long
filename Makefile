
###### SOURCES ######################################


SRCS =			berfile.c \
				berfile2.c \
				events.c \
				game_manager.c \
				get_next_line.c \
				get_next_line_utils.c \
				graphics.c \
				movement.c \
				parsing.c \
				so_long.c \
				valid_path_checker.c

SRCS_BONUS =	berfile_bonus.c \
				berfile2_bonus.c \
				events_bonus.c \
				game_manager_bonus.c \
				get_next_line.c \
				get_next_line_utils.c \
				graphics_bonus.c \
				movement_bonus.c \
				parsing_bonus.c \
				so_long_bonus.c \
				valid_path_checker_bonus.c


###### VARIABLES ####################################


CC = 			cc

CFLAGS = 		-Wall -Wextra -Werror

VPATH = 		mandatory/:mandatory/parsing/:mandatory/game/:bonus/:bonus/parsing/:bonus/game/:utils/get_next_line/

OBJ_DIR = 		obj_files

OBJS = 			$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

OBJS_BONUS = 			$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))

LIBFT = 		utils/libft/libft.a

NAME = 			so_long


###### RULES #######################################


all: mlx $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -L./minilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

$(LIBFT):
	cd utils/libft && make

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I./minilibx-linux/ -c $< -o $@

mlx:
	cd minilibx-linux && make

clean:
	rm -rf $(OBJ_DIR)
	cd utils/libft && make clean
	cd minilibx-linux && make clean

fclean: clean
	rm -rf $(NAME)
	cd utils/libft && rm -rf libft.a

re: fclean all

bonus: $(OBJ_DIR) $(LIBFT) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIBFT) -L./minilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

.PHONY: all clean fclean re bonus mlx