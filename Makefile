NAME	=	cub3D

CC		=	cc
CFLAGS	= 	-Wall -Wextra -Werror -g3
LDFLAGS	= 	-lreadline -lncurses $(MLX_LIB)

MLX_DIR = ./minilibx-linux
MLX_INC = -I$(MLX_DIR)
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

INC_DIR = ./inc
INCLUDES = -I$(INC_DIR) $(MLX_INC)

SRCS	= ./src/main.c ./src/parsing/parsing.c ./src/parsing/parsing_utils.c ./src/parsing/helper.c \
			./src/extract/extract.c ./src/extract/extract_utils.c ./src/extract/extract_utils2.c
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
