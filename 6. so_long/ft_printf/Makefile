# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albmarqu <albmarqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 20:54:51 by albmarqu          #+#    #+#              #
#    Updated: 2024/07/11 19:55:38 by albmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c \
		ftp_putchar.c \
		ftp_putstr.c \
		ftp_putnbr.c \
		ftp_puthex.c
	
OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
$(OBJECTS): $(FILES)
	gcc -Wall -Werror -Wextra -I. -c $(FILES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all