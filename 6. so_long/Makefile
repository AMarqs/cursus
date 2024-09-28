# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 22:39:41 by albmarqu          #+#    #+#              #
#    Updated: 2024/09/28 16:13:22 by albmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBMLX = ./MLX42
LIBFT = ./libft
PRINTF = ./ft_printf

HEADERS = -I $(LIBMLX) -I $(LIBFT) -I $(PRINTF)
LIBRARIES = $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
GLFW = -lglfw
SRC = 	so_long.c \
		args_check.c \
		map_check.c \
		floodfill.c \
		map.c \
		game.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c
SRCS = $(addprefix src/, $(SRC))
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -g -Ofast -fsanitize=address
CC = clang

all: $(NAME)

$(NAME): $(OBJS) libmlx libft ft_printf
	@$(CC) $(OBJS) $(LIBRARIES) $(GLFW) $(HEADERS) -o $(NAME)
	
%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $< \n)"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

ft_printf:
	@make -C $(PRINTF)
	
clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx libft ft_printf