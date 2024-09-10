/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:51:12 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/10 14:29:33 by albmarqu         ###   ########.fr       */
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
#  define HEIGHT 32
# endif

# ifndef WIDTH
#  define WIDTH 32
# endif

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
	int		p;
	int		c;
	int		e;
	int		x;
	int		y;
}	t_map;

typedef struct s_image
{
	mlx_texture_t	*t_floor;
	mlx_image_t		*i_floor;
	mlx_texture_t	*t_wall;
	mlx_image_t		*i_wall;
	mlx_image_t		*i_char;
	mlx_texture_t	*t_char;
	mlx_texture_t	*t_col;
	mlx_image_t		*i_col;
	mlx_texture_t	*t_exit;
	mlx_image_t		*i_exit;
}	t_image;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	int			cont;
}	t_game;

char	*get_next_line(int fd);
bool	border(char **map, int row, int col);
bool	check_characters(t_map *map);
bool	path(t_map *map);
void	mapping(t_map *map, mlx_t *mlx);

#endif