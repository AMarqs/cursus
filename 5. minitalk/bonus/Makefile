# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 21:31:48 by albmarqu          #+#    #+#              #
#    Updated: 2024/08/08 21:53:09 by albmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
FILES_C = client.c
OBJECTS_C = $(FILES_C:.c=.o)

NAME_S = server
FILES_S = server.c
OBJECTS_S = $(FILES_S:.c=.o)

PRINTF = ./printf
LIBFT = ./libft


%.o: %.c minitalk.h
	@gcc -Wall -Werror -Wextra -I. -c $< -o $@

all: $(NAME_C) $(NAME_S)

printf:
	@make -C $(PRINTF)

libft:
	@make -C $(LIBFT)
	
$(NAME_C): $(OBJECTS_C) printf libft
	@gcc $(OBJECTS_C) -o $(NAME_C) -L$(PRINTF) -lftprintf -L$(LIBFT) -lft

$(NAME_S): $(OBJECTS_S) printf libft
	@gcc $(OBJECTS_S) -o $(NAME_S) -L$(PRINTF) -lftprintf -L$(LIBFT) -lft


clean:
	@make fclean -C $(PRINTF) 
	@make fclean -C $(LIBFT)
	@rm -f $(OBJECTS_C) $(OBJECTS_S)

fclean: clean
	@rm -f $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all clean printf libft fclean re
