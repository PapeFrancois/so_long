
###### SOURCES ######################################


SRCS =			so_long.c


###### VARIABLES ####################################


CC = 			cc

CFLAGS = 		-Wall -Wextra -Werror

VPATH = 		mandatory/

OBJ_DIR = 		obj_files

OBJS = 			$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

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

.PHONY: all clean fclean re mlx