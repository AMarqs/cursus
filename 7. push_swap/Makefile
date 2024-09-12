# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 16:01:18 by albmarqu          #+#    #+#              #
#    Updated: 2024/09/12 17:32:27 by albmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft

HEADERS = -I $(LIBFT)
LIBRARIES = $(LIBFT)/libft.a

SRC = 	push_swap.c \
		args_checking.c
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