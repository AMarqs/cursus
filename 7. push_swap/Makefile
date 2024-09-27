# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 16:01:18 by albmarqu          #+#    #+#              #
#    Updated: 2024/09/27 20:30:23 by albmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft

HEADERS = -I $(LIBFT)
LIBRARIES = $(LIBFT)/libft.a

SRCS = 	main.c \
		args_checking.c \
		create_stack.c \
		normalize.c \
		swap.c \
		push.c \
		rotate.c \
		reverse.c \
		basics.c \
		algorithm.c \
		pos_utils.c \
		costs.c \
		movement.c
SRC = $(addprefix src/, $(SRCS))
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -Ofast -g
CC = clang

all: $(NAME)

$(NAME): $(OBJ) libft
	@$(CC) $(OBJ) $(LIBRARIES) $(HEADERS) -o $(NAME)
	
%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $< \n)"

libft:
	@make -C $(LIBFT)

clean:
	@rm -rf $(OBJ)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft