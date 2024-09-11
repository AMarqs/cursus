/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:15:18 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/11 13:44:52 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_texture(t_image *image, t_game *game)
{
	image->t_floor = mlx_load_png("./textures/floor.png");
	image->t_wall = mlx_load_png("./textures/wall.png");
	image->t_play = mlx_load_png("./textures/player.png");
	image->t_col = mlx_load_png("./textures/collect.png");
	image->t_exit = mlx_load_png("./textures/exit.png");
	if (!image->t_floor || !image->t_wall || !image->t_play
		|| !image->t_col || !image->t_exit)
	{
		write(2, "Error\nError loading texture\n", 28);
		free_image(image);
		f_close(game);
		exit(EXIT_FAILURE);
	}
}

void	load_image(t_image *image, mlx_t *mlx, t_game *game)
{
	image->i_floor = mlx_texture_to_image(mlx, image->t_floor);
	image->i_wall = mlx_texture_to_image(mlx, image->t_wall);
	image->i_play = mlx_texture_to_image(mlx, image->t_play);
	image->i_col = mlx_texture_to_image(mlx, image->t_col);
	image->i_exit = mlx_texture_to_image(mlx, image->t_exit);
	if (!image->i_floor || !image->i_wall || !image->i_play
		|| !image->i_col || !image->i_exit)
	{
		write(2, "Error\nError creating image\n", 27);
		free_image(image);
		f_close(game);
		exit(EXIT_FAILURE);
	}
}

void	display(t_game *game, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(game->mlx, image, x, y) < 0)
	{
		write(2, "Error\nError displaying image\n", 29);
		free_image(game->image);
		f_close(game);
		exit(EXIT_FAILURE);
	}
}

void	init_image(t_game *game)
{
	game->image = malloc(sizeof(t_image));
	if (game->image == NULL)
	{
		write(2, "Error\nError allocating memory\n", 30);
		f_close(game);
		exit(EXIT_FAILURE);
	}
	load_texture(game->image, game);
	load_image(game->image, game->mlx, game);
}

void	mapping(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	init_image(game);
	while (++i < game->map->row)
	{
		j = -1;
		while (++j < game->map->col)
		{
			display(game, game->image->i_floor, (i * HEIGHT), (j * WIDTH));
			if (game->map->map[i][j] == '1')
				display(game, game->image->i_wall, (i * HEIGHT), (j * WIDTH));
			else if (game->map->map[i][j] == 'P')
				display(game, game->image->i_play, (i * HEIGHT), (j * WIDTH));
			else if (game->map->map[i][j] == 'C')
				display(game, game->image->i_col, (i * HEIGHT), (j * WIDTH));
			else if (game->map->map[i][j] == 'E')
				display(game, game->image->i_exit, (i * HEIGHT), (j * WIDTH));
		}
	}
	free_image(game->image);
}
