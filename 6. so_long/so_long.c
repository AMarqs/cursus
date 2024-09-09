/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:53:11 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/09 21:24:09 by albmarqu         ###   ########.fr       */
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
			while (map->row >= 0)
				free(map->map[map->row--]);
			free(map->map);
			free(map);
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
		while (map->row >= 0)
			free(map->map[map->row--]);
		free(map->map);
		free(map);
		exit(EXIT_FAILURE);
	}
	else if (!check_characters(map))
	{
		write(2, "Error\nWrong characters\n", 23);
		while (map->row >= 0)
			free(map->map[map->row--]);
		free(map->map);
		free(map);
		exit(EXIT_FAILURE);
	}
	else if (!path(map->map, map->row, map->col))
	{
		write(2, "Error\nMap validation failed: no path\n", 37);
		while (map->row >= 0)
			free(map->map[map->row--]);
		free(map->map);
		free(map);
		exit(EXIT_FAILURE);
	}
	
	mlx = mlx_init((map->row * HEIGHT), (map->col * WIDTH), "so_long", false);
	//if (!mlx)
    //    exit(EXIT_FAILURE);

	mapping(map, mlx);

	mlx_loop(mlx);
	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	//mlx_delete_image(mlx, img);
	//mlx_delete_texture(texture);
	//mlx_terminate(mlx);
	
	while (map->row >= 0)
		free(map->map[map->row--]);
	free(map->map);
	free(map);
	return (0);
}




