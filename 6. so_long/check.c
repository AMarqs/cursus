/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:41:53 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/09 22:00:18 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	border(char **map, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (map[0][i] != '1' || map[row - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (map[i][0] != '1' || map[i][col - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	characters(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->p = 0;
	map->e = 0;
	map->c = 0;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map->map[i][j] == 'P')
				map->p++;
			else if (map->map[i][j] == 'E')
				map->e++;
			else if (map->map[i][j] == 'C')
				map->c++;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != '\n')
				return (false);
		}
	}
	return (true);
}

bool	check_characters(t_map *map)
{
	if (!characters(map))
		return (false);
	if (map->p == 1 && map->e == 1 && map->c >= 1)
		return (true);
	else if (map->p != 1)
		write(2, "Error\nWrong number of players (1 required)\n", 43);
	else if (map->e != 1)
		write(2, "Error\nWrong number of exits (1 required)\n", 41);
	else if (map->c < 1)
		write(2, "Error\nWrong number of collectibles (minimum 1 required)\n", 56);
	return (false);
}
