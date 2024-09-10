/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:45:13 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/10 14:01:28 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

void	free_copy(char **map_copy, int row)
{
	while (row >= 0)
		free(map_copy[row--]);
	free(map_copy);
}

bool	flood(t_map *map, int x, int y)
{
	char 	**map_copy;
	int		i;
	int		j;

	map_copy = malloc((map->row + 1) * sizeof(char *));
	i = -1;
	while (++i < map->row)
		map_copy[i] = ft_strdup(map->map[i]);
	map_copy[map->row] = NULL;
	floodfill(map_copy, x, y);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				free_copy(map_copy, map->row);
				return (false);
			}
		}
	}
	free_copy(map_copy, map->row);
	return (true);
}

bool	path(t_map *map)
{
	int	i;
	int	j;
	

	map->x = 0;
	map->y = 0;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map->map[i][j] == 'P')
			{
				map->x = i;
				map->y = j;
			}
		}
	}
	if (!flood(map, map->x, map->y))
		return (false);
	return (true);
}
