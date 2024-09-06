/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:53:11 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/06 14:22:09 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		file;
	int		row;
	int		col;
	char	**map;
	char	*line;

	row = 0;
	col = 0;
	if (argc != 2)
	{
		ft_printf("More than 1 argument\n");
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_printf("Error opening file\n");
		return (1);
	}
	line = get_next_line(file);
	while (line)
	{
		line = get_next_line(file);
		free(line);
		row++;
	}
	map = malloc((row + 1) * sizeof(char *));
	if (map == NULL)
	{
		ft_printf("Error allocating memory\n");
		return (1);
	}
	line = get_next_line(file);
	col = (int)ft_strlen(line);
	while (line)
	{
		map[row] = line;
		line = get_next_line(file);
		if ((int)ft_strlen(map[row]) != col)
		{
			free(map);
			while (row >= 0)
				free(map[row--]);
			free(line);
			ft_printf("Map is not rectangular\n");
			return (1);
		}
		row++;
	}
	close(file);
	if (!border(map, row, col) || !characters(map, row, col)
		|| !path(map, row, col))
	{
		ft_printf("Map validation failed\n");
		return (1);
	}
	ft_printf("Map validation succeeded\n");
	return (0);
}
/*
------- el mapa se introduce como un fichero .ber -----------

YA - primera y ultima linea que sean unos 
YA - primera y ultima columna que sean unos
YA - solo un P y un E
YA - como minimo un C
YA - solo caracteres P, E, C, 1 y 0
camino de 0 entre P y E, pasando por todos los C (floodfill)
buscar sprits, mapas y texturas
*/


// mlx_t		*mlx;
// mlx_image_t	*image;
// mlx = mlx_init(1000, 1000, "so_long", false);