/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:53:11 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/10 14:32:13 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	free_map(t_map *map)
{
	while (map->row >= 0)
		free(map->map[map->row--]);
	free(map->map);
	free(map);
}

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
	if (game->map->map[game->map->x + x][game->map->y + y] == 'E' && game->map->c != 0)
		return ;
	if (game->map->map[game->map->x + x][game->map->y + y] == 'E' && game->map->c == 0)
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
	mapping(game->map, game->mlx);
}

void	f_key(mlx_key_data_t keydata, void* param)
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

int	main(int argc, char **argv)
{
	int		file;
	t_map	*map;
	char	*line;
	mlx_t	*mlx;

	if (argc != 2)
	{
		write(2, "Error\nMore than 1 argument\n", 27);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".ber", 4))
	{
		write(2, "Error\nBad extension\n", 20);
		exit(EXIT_FAILURE);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(2, "Error\nError opening file\n", 25);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(file);
	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		write(2, "Error\nError allocating memory\n", 30);
		exit(EXIT_FAILURE);
	}
	map->row = 0;
	while (line)
	{
		free(line);
		line = get_next_line(file);
		map->row++;
	}
	close(file);
	file = open(argv[1], O_RDONLY);
	map->map = malloc((map->row + 1) * sizeof(char *));
	if (map->map == NULL)
	{
		write(2, "Error\nError allocating memory\n", 30);
		free(map);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(file);
	map->col = ft_strlen2(line);
	map->row = 0;
	while (line)
	{
		map->map[map->row] = line;
		if (ft_strlen2(map->map[map->row]) != map->col)
		{
			free_map(map);
			write(2, "Error\nNo rectangular\n", 21);
			close(file);
			exit(EXIT_FAILURE);
		}
		line = get_next_line(file);
		map->row++;
	}
	map->map[map->row] = NULL;
	close(file);
	if (!border(map->map, map->row, map->col))
	{
		write(2, "Error\nNot surrounded by walls\n", 30);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	else if (!check_characters(map))
	{
		write(2, "Error\nWrong characters\n", 23);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	else if (!path(map))
	{
		write(2, "Error\nMap validation failed: no path\n", 37);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	
	mlx = mlx_init((map->row * HEIGHT), (map->col * WIDTH), "so_long", false);
	if (!mlx)
	{
		write(2, "Error\nError initializing mlx\n", 30);
		free_map(map);
		exit(EXIT_FAILURE);
	}

	mapping(map, mlx);




	t_game	*game;
	game = malloc(sizeof(t_game));
	game->map = map;
	game->mlx = mlx;
	game->cont = 0;
	mlx_close_hook(mlx, f_close, game);
	mlx_key_hook(mlx, f_key, game);






	mlx_loop(mlx);
	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	//mlx_delete_image(mlx, img);
	//mlx_delete_texture(texture);
	//mlx_terminate(mlx);
	
	free_map(map);
	return (0);
}




