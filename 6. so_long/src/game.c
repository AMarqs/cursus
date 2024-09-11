/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:23:27 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/11 17:14:50 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_map(game->map);
	mlx_terminate(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}

void	move(t_game *game, int x, int y)
{
	if (game->map->map[game->map->x + x][game->map->y + y] == '1')
		return ;
	if (game->map->map[game->map->x + x][game->map->y + y] == 'E'
		&& game->map->c != 0)
		return ;
	if (game->map->map[game->map->x + x][game->map->y + y] == 'E'
		&& game->map->c == 0)
	{
		printf("You win!\n");
		f_close(game);
	}
	if (game->map->map[game->map->x + x][game->map->y + y] == 'C')
		game->map->c--;
	game->map->map[game->map->x][game->map->y] = '0';
	game->map->map[game->map->x + x][game->map->y + y] = 'P';
	game->map->x += x;
	game->map->y += y;
	game->cont++;
	ft_printf("Movements: %d\n", game->cont);
	mapping(game);
}

void	f_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		f_close(game);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move(game, 0, -1);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move(game, -1, 0);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move(game, 0, 1);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move(game, 1, 0);
}

t_game	*init_game(t_map *map)
{
	mlx_t	*mlx;
	t_game	*game;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init((map->row * HEIGHT), (map->col * WIDTH), "so_long", true);
	if (!mlx)
	{
		write(2, "Error\nError initializing mlx\n", 30);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	game = malloc(sizeof(t_game));
	if (game == NULL)
	{
		write(2, "Error\nError allocating memory\n", 30);
		free_map(map);
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
	game->map = map;
	game->mlx = mlx;
	game->image = NULL;
	game->cont = 0;
	return (game);
}
