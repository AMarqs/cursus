/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:15:18 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/09 21:18:05 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 	mapping(t_map *map, mlx_t *mlx)
{
	t_image	*image;
	int 	i;
	int 	j;
	
	i = 0;
	image = malloc(sizeof(t_image));
	image->t_floor = mlx_load_png("./sprites/floor.png");
	image->t_wall = mlx_load_png("./sprites/wall.png");
	image->t_char = mlx_load_png("./sprites/character.png");
	image->t_col = mlx_load_png("./sprites/collect.png");
	image->t_exit = mlx_load_png("./sprites/exit.png");
	//if (!texture)
    //    exit(EXIT_FAILURE);
	image->i_floor = mlx_texture_to_image(mlx, image->t_floor);
	image->i_wall = mlx_texture_to_image(mlx, image->t_wall);
	image->i_char = mlx_texture_to_image(mlx, image->t_char);
	image->i_col = mlx_texture_to_image(mlx, image->t_col);
	image->i_exit = mlx_texture_to_image(mlx, image->t_exit);
	//if (!image)
    //    exit(EXIT_FAILURE);
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			mlx_image_to_window(mlx, image->i_floor, (i * HEIGHT), (j * WIDTH));
			if (map->map[i][j] == '1')
				mlx_image_to_window(mlx, image->i_wall, (i * HEIGHT), (j * WIDTH));
			else if (map->map[i][j] == 'P')
				mlx_image_to_window(mlx, image->i_char, (i * HEIGHT), (j * WIDTH));
			else if (map->map[i][j] == 'C')
				mlx_image_to_window(mlx, image->i_col, (i * HEIGHT), (j * WIDTH));
			else if (map->map[i][j] == 'E')
				mlx_image_to_window(mlx, image->i_exit, (i * HEIGHT), (j * WIDTH));
			// if (mlx_image_to_window(mlx, image, 0, 0) < 0)
    		//     exit(EXIT_FAILURE);
			j++;
		}
		i++;
	}
}
