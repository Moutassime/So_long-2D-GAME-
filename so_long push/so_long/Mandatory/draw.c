/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:34:22 by eseiv             #+#    #+#             */
/*   Updated: 2022/02/18 15:34:24 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_render(t_map *map, int i, int j)
{
	while (++i < map->hauteur)
	{
		j = -1;
		while (++j < map->largeur)
		{
			if (map->field[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_wall, j * 48, i * 48);
			else
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_path, j * 48, i * 48);
				if (map->field[i][j] == 'P')
					mlx_put_image_to_window(map->mlx, map->mlx_win, \
					map->texture_yugi, j * 48, i * 48);
				else if (map->field[i][j] == 'C')
					mlx_put_image_to_window(map->mlx, map->mlx_win, \
					map->texture_dragon, j * 48, i * 48);
				else if (map->field[i][j] == 'E')
					mlx_put_image_to_window(map->mlx, map->mlx_win, \
					map->texture_exit, j * 48, i * 48);
			}
		}
	}
}

void	game_init(t_map *map)
{
	map->texture_yugi = mlx_xpm_file_to_image(map->mlx, \
	"Mandatory/Xpms/yugi_right.xpm", &map->img_largeur, &map->img_hauteur);
	map->texture_exit = mlx_xpm_file_to_image(map->mlx, \
	"MAndatory/Xpms/kaiba.xpm", &map->img_largeur, &map->img_largeur);
	map->texture_path = mlx_xpm_file_to_image(map->mlx, \
	"MAndatory/Xpms/path.xpm", &map->img_largeur, &map->img_hauteur);
	map->texture_wall = mlx_xpm_file_to_image(map->mlx, \
	"Mandatory/Xpms/wall.xpm", &map->img_largeur, &map->img_hauteur);
	map->texture_dragon = mlx_xpm_file_to_image(map->mlx, \
	"Mandatory/Xpms/dragon.xpm", &map->img_largeur, &map->img_hauteur);
	if (!map->texture_yugi || !map->texture_exit || !map->texture_path \
		|| !map->texture_wall || !map->texture_dragon)
	{
		perror("Error with xpm files");
		free (map->field);
		exit(EXIT_FAILURE);
	}
	map_render(map, -1, -1);
}
