# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 22:39:41 by albmarqu          #+#    #+#              #
#    Updated: 2024/08/08 22:47:27 by albmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBMLX = ./MLX42
LIBFT = ./libft

HEADERS = -I $(LIBMLX) -I $(LIBFT)
LIBRARIES = $(LIBMLX)/libmlx.a $(LIBFT)/libft.a
GLFW = -lglfw
SRCS = so_long.c
OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -Ofast
CC = gcc

all: $(NAME)

$(NAME): $(OBJS) libft libmlx
	@$(CC) $(OBJS) $(LIBS) $(GLFW) $(HEADERS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $< \n)"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx libft