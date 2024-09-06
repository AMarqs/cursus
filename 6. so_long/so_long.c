/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:53:11 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/06 22:07:52 by albmarqu         ###   ########.fr       */
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
	int		row;
	int		col;
	char	**map;
	char	*line;

	row = 0;
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
	while (line)
	{
		free(line);
		line = get_next_line(file);
		row++;
	}
	close(file);
	file = open(argv[1], O_RDONLY);
	map = malloc((row + 1) * sizeof(char *));
	if (map == NULL)
	{
		write(2, "Error\nError allocating memory\n", 30);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(file);
	col = ft_strlen2(line);
	row = 0;
	while (line)
	{
		map[row] = line;
		if (ft_strlen2(map[row]) != col)
		{
			while (row >= 0)
				free(map[row--]);
			free(map);
			write(2, "Error\nNo rectangular\n", 21);
			close(file);
			exit(EXIT_FAILURE);
		}
		line = get_next_line(file);
		row++;
	}
	map[row] = NULL;
	close(file);
	if (!border(map, row, col))
	{
		write(2, "Error\nNot surrounded by walls\n", 30);
		exit(EXIT_FAILURE);
	}
	else if (!characters(map, row, col))
	{
		write(2, "Error\nWrong characters\n", 23);
		exit(EXIT_FAILURE);
	}
	else if (!path(map, row, col))
	{
		write(2, "Error\nMap validation failed: no path\n", 37);
		exit(EXIT_FAILURE);
	}
	while (row >= 0)
		free(map[row--]);
	free(map);


	
	
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_texture_t* 	texture;

	mlx = mlx_init((1000), (1000), "so_long", false);
	
	//mlx = mlx_init((row * HEIGHT), (col * WIDTH), "so_long", false);
	//if (!mlx)
    //    exit(EXIT_FAILURE);
	
	texture = mlx_load_png("./textures/sprites/tilesets/grass.png");
	//if (!texture)
    //    exit(EXIT_FAILURE);
	
	// Convert texture to a displayable image
	
	image = mlx_texture_to_image(mlx, texture);
	//if (!image)
    //    exit(EXIT_FAILURE);
	
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_image_to_window(mlx, image, 32, 32);
	mlx_image_to_window(mlx, image, 64, 64);

	// Display the image
	// if (mlx_image_to_window(mlx, image, 0, 0) < 0)
    //     exit(EXIT_FAILURE);

	mlx_loop(mlx);
	while (1)
		row++;
	
	
	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	//mlx_delete_image(mlx, img);
	//mlx_delete_texture(texture);
	//mlx_terminate(mlx);
	
	//return (EXIT_SUCCESS);


	
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
