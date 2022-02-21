/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:59:09 by eseiv             #+#    #+#             */
/*   Updated: 2022/02/20 22:02:27 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	destroy_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	free_all(map);
	printf("Closing the window!\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_all(t_map *map)
{
	int	i;

	i = -1;
	if (map->field)
	{
		while (++i < map->hauteur)
			if (map->field[i])
				free(map->field[i]);
		if (map->field)
			free(map->field);
	}
	if (map->mlx)
	{
		mlx_destroy_image(map->mlx, map->texture_bdragon);
		mlx_destroy_image(map->mlx, map->texture_sliver);
		mlx_destroy_image(map->mlx, map->texture_wall);
		mlx_destroy_image(map->mlx, map->texture_yugi);
		mlx_destroy_image(map->mlx, map->texture_exit);
		free(map->mlx);
	}
}

void	ft_exit(t_map *map, int i)
{
	if (i == 0)
		ft_printf ("You win!\n");
	else if (i == 1)
		ft_printf ("You lose!\n");
	free_all(map);
	exit (EXIT_SUCCESS);
}

void	player_moves(t_map *map, int i, int j)
{
	if (map->field[map->p_x + i][map->p_y + j] != '1')
	{
		if (map->field[map->p_x + i][map->p_y + j] == 'C')
			map->collect--;
		else if (map->field[map->p_x + i][map->p_y + j] == 'E' \
				&& map->collect == 0)
			ft_exit(map, 0);
		else if (map->field[map->p_x + i][map->p_y + j] == 'E' \
				&& map->collect != 0)
			return ;
		else if (map->field[map->p_x + i][map->p_y + j] == 'S')
			ft_exit (map, 1);
		map->steps++;
		map->field[map->p_x + i][map->p_y + j] = 'P';
		map->field[map->p_x][map->p_y] = '0';
		map->p_x += i;
		map->p_y += j;
		map_render(map, -1, -1);
	}
}

int	key_hook(int key_code, t_map *map)
{
	if (key_code == ESC)
		destroy_window(map);
	else if (key_code == A)
	{
		map->texture_yugi = mlx_xpm_file_to_image(map->mlx, \
		"Bonus/Xpms/yugi_left1.xpm", &map->img_largeur, &map->img_hauteur);
		player_moves(map, 0, -1);
		map->direction = 'L';
	}
	else if (key_code == W)
		player_moves(map, -1, 0);
	else if (key_code == D)
	{
		map->texture_yugi = mlx_xpm_file_to_image(map->mlx, \
		"Bonus/Xpms/yugi1.xpm", &map->img_largeur, &map->img_hauteur);
		player_moves(map, 0, 1);
		map->direction = 'R';
	}
	else if (key_code == S)
		player_moves(map, 1, 0);
	return (0);
}
