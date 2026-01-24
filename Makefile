NAME	=	cub3D

CC = cc
CFLAGS	= 	-Wall -Wextra -Werror -g3
LDFLAGS	= 	-lreadline -lncurses $(MLX_LIB)

MLX_DIR = ./minilibx-linux
MLX_INC = -I$(MLX_DIR)
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

INC_DIR = ./inc
INCLUDES = -I$(INC_DIR) $(MLX_INC)

SRCS	=	./src/main.c \
			./src/helper/free_helper.c \
			./src/helper/hook_helper.c \
			./src/helper/init.c \
			./src/helper/init_helper.c \
<<<<<<< HEAD
			./src/helper/main_helper.c \
			./src/helper/move_helper.c \
			./src/helper/raycasting_helper.c \
			./src/parsing/helper.c \
			./src/parsing/parsing.c \
			./src/parsing/parsing_utils.c \
=======
			./src/helper/move_helper.c \
			./src/helper/raycasting_helper.c \
>>>>>>> debug
			./src/raycasting/loop.c \
			./src/raycasting/raycasting.c \
			./src/parser/checkers.c \
			./src/parser/dealloc_funcs.c \
			./src/parser/init.c \
			./src/parser/map_parser.c \
			./src/parser/parser_helpers.c \
			./src/parser/parser.c \
			./src/parser/player_init.c \
			./src/parser/utils.c \
			./src/parser/validation_checkers.c \
			./src/parser/validation_helpers.c \
			./src/parser/validation.c

OBJS	= 	$(SRCS:%.c=%.o)

LIBFT_DIR	= 	./libft
LIBFT_A		= 	$(LIBFT_DIR)/libft.a



all: $(LIBFT_A)  $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
