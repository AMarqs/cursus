/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:53:11 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/11 12:51:43 by albmarqu         ###   ########.fr       */
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

void	free_image(t_image *image)
{
	if (image->t_floor)
		mlx_delete_texture(image->t_floor);
	if (image->t_wall)
		mlx_delete_texture(image->t_wall);
	if (image->t_play)
		mlx_delete_texture(image->t_play);
	if (image->t_col)
		mlx_delete_texture(image->t_col);
	if (image->t_exit)
		mlx_delete_texture(image->t_exit);
	free(image);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	check_args(argc, argv);
	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		write(2, "Error\nError allocating memory\n", 30);
		exit(EXIT_FAILURE);
	}
	check_file(argv, map);
	create_map(argv, map);
	check_map(map);
	game = init_game(map);
	mapping(game);
	mlx_close_hook(game->mlx, f_close, game);
	mlx_key_hook(game->mlx, f_key, game);
	mlx_loop(game->mlx);
	free_map(map);
	return (0);
}
