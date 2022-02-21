/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:58:42 by eseiv             #+#    #+#             */
/*   Updated: 2022/02/20 21:58:44 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_map *map, int i, int j, void *img_ptr)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	img_ptr, j * 48, i * 48);
}

void	show_moves(t_map *map)
{
	char	*leak;

	leak = NULL;
	map->texture_black = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/just_black.xpm", &map->img_largeur, &map->img_hauteur);
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	map->texture_black, 0, 0);
	mlx_string_put(map->mlx, map->mlx_win, 2, 2, 0xFFFF00, "Moves: ");
	leak = ft_itoa(map->steps);
	mlx_string_put(map->mlx, map->mlx_win, 70, 2, 0xFF0000, leak);
	free(leak);
}

void	map_render(t_map *map, int i, int j)
{
	while (++i < map->hauteur)
	{
		j = -1;
		while (++j < map->largeur)
		{
			if (map->field[i][j] == '1')
				put_img(map, i, j, map->texture_wall);
			else
			{
				put_img(map, i, j, map->texture_path);
				if (map->field[i][j] == 'P')
					put_img(map, i, j, map->texture_yugi);
				else if (map->field[i][j] == 'C')
					put_img(map, i, j, map->texture_bdragon);
				else if (map->field[i][j] == 'E')
					put_img(map, i, j, map->texture_exit);
				else if (map->field[i][j] == 'S')
					put_img(map, i, j, map->texture_sliver);
			}
		}
	}
	show_moves(map);
}

void	game_init(t_map *map)
{
	map->texture_yugi = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/yugi1.xpm", &map->img_largeur, &map->img_hauteur);
	map->texture_sliver = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/sliver.xpm", &map->img_largeur, &map->img_hauteur);
	map->texture_exit = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/yugi_house.xpm", &map->img_largeur, &map->img_largeur);
	map->texture_path = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/path.xpm", &map->img_largeur, &map->img_hauteur);
	map->texture_wall = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/wall.xpm", &map->img_largeur, &map->img_hauteur);
	map->texture_bdragon = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/bdragon.xpm", &map->img_largeur, &map->img_hauteur);
	if (!map->texture_yugi || !map->texture_exit || !map->texture_path \
		|| !map->texture_wall || !map->texture_bdragon || !map->texture_sliver)
	{
		perror("Error with xpm files");
		free(map->field);
		exit(EXIT_FAILURE);
	}
	map_render(map, -1, -1);
}
