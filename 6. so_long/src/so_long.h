/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:51:12 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/10 19:15:16 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdint.h>
# include <limits.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
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
	mlx_texture_t	*t_play;
	mlx_image_t		*i_play;
	mlx_texture_t	*t_col;
	mlx_image_t		*i_col;
	mlx_texture_t	*t_exit;
	mlx_image_t		*i_exit;
}	t_image;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_image		*image;
	int			cont;
}	t_game;

char	*get_next_line(int fd);

int		ft_strlen2(const char *s);
void	free_map(t_map *map);
void	free_image(t_image *image);

void	check_args(int argc, char **argv);
void	check_file(char **argv, t_map *map);
void	fill_map(int file, t_map *map);
void	create_map(char **argv, t_map *map);

bool	border(char **map, int row, int col);
bool	characters(t_map *map);
bool	check_characters(t_map *map);
void	check_map(t_map *map);

void	free_copy(char **map_copy, int row);
void	floodfill(char **map, int x, int y);
char	**copy_map(t_map *map);
bool	flood(t_map *map, int x, int y);
bool	path(t_map *map);

void	load_texture(t_image *image, t_game *game);
void	load_image(t_image *image, mlx_t *mlx, t_game *game);
void	display(t_game *game, mlx_image_t *image, int x, int y);
void	init_image(t_game *game);
void	mapping(t_game *game);

void	f_close(void *param);
void	move(t_game *game, int x, int y);
void	f_key(mlx_key_data_t keydata, void *param);
t_game	*init_game(t_map *map);

#endif