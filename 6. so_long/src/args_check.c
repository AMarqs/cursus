/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:28:18 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/11 12:48:02 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char **argv)
{
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
}

void	check_file(char **argv, t_map *map)
{
	int		file;
	char	*line;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(2, "Error\nError opening file\n", 25);
		exit(EXIT_FAILURE);
	}
	map->row = 0;
	line = get_next_line(file);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		map->row++;
	}
	close(file);
}

void	fill_map(int file, t_map *map)
{
	char	*line;

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
}

void	create_map(char **argv, t_map *map)
{
	int		file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(2, "Error\nError opening file\n", 25);
		exit(EXIT_FAILURE);
	}
	map->map = malloc((map->row + 1) * sizeof(char *));
	if (map->map == NULL)
	{
		close(file);
		write(2, "Error\nError allocating memory\n", 30);
		free(map);
		exit(EXIT_FAILURE);
	}
	fill_map(file, map);
	close(file);
}
