/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:41:53 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/06 14:23:37 by albmarqu         ###   ########.fr       */
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

bool	characters(char **map, int row, int col)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = 0;
	j = 0;
	p = 0;
	e = 0;
	c = 0;
	while (i < row)
	{
		while (j < col)
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'C')
				c++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (false);
			j++;
		}
		i++;
	}
	if (p == 1 && e == 1 && c >= 1)
		return (true);
	return (false);
}

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

bool	path(char **map, int row, int col)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	c;
	char **map_copy;

	x = -1;
	y = -1;
	i = 0;
	j = 0;
	c = 0;
	while (i < row)
	{
		while (j < col)
		{
			if (map[i][j] == 'P')
			{
				x = i;
				y = j;
			}
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (x == -1 || y == -1)
		return (false);
	map_copy = malloc((row + 1) * sizeof(char *));
	i = 0;
	while (i < row)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	floodfill(map_copy, x, y);
	while (i < row)
	{
		while (j < col)
		{
			if (map[i][j] == 'C' && map_copy[i][j] == 'E')
			{
				free(map_copy);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

