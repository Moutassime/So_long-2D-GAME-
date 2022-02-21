/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:59:42 by eseiv             #+#    #+#             */
/*   Updated: 2022/02/20 21:59:43 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	file_to_img(t_map *map, char *file)
{
	map->texture_yugi = mlx_xpm_file_to_image(map->mlx, \
	file, &map->img_largeur, &map->img_hauteur);
}

void	yugi_right_update(t_map *map)
{
	if (map->count >= 0)
		file_to_img(map, "Bonus/Xpms/yugi1.xpm");
	if (map->count >= 25)
		file_to_img(map, "Bonus/Xpms/yugi2.xpm");
	if (map->count >= 40)
		file_to_img(map, "Bonus/Xpms/yugi3.xpm");
}

void	yugi_left_update(t_map *map)
{
	if (map->count >= 0)
		file_to_img(map, "Bonus/Xpms/yugi_left1.xpm");
	if (map->count >= 25)
		file_to_img(map, "Bonus/Xpms/yugi_left2.xpm");
	if (map->count >= 40)
		file_to_img(map, "Bonus/Xpms/yugi_left3.xpm");
}

int	yugi_update(t_map *map)
{
	map->count++;
	if (map->count <= 50)
	{
		if (map->direction == 'R')
			yugi_right_update(map);
		else
			yugi_left_update(map);
	}
	else
		map->count = 0;
	map_render(map, -1, -1);
	return (0);
}
