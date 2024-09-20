# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 16:01:18 by albmarqu          #+#    #+#              #
#    Updated: 2024/09/20 18:50:47 by albmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft

HEADERS = -I $(LIBFT)
LIBRARIES = $(LIBFT)/libft.a

SRC = 	push_swap.c \
		args_checking.c \
		create_stack.c \
		normalize.c \
		# sa_sb_ss.c \
		# pa_pb.c \
		# ra_rb_rr.c \
		# rra_rrb_rrr.c \
		# basics.c
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