/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:51:12 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/06 21:39:22 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h> ///
# include <math.h>
# include <stdint.h>
# include <limits.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line_bonus.h"

# ifndef HEIGHT
#  define HEIGHT 10
# endif

# ifndef WIDTH
#  define WIDTH 10
# endif

char	*get_next_line(int fd);
bool	border(char **map, int row, int col);
bool	characters(char **map, int row, int col);
bool	path(char **map, int row, int col);

#endif