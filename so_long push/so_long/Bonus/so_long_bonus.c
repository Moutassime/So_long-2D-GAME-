/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:59:20 by eseiv             #+#    #+#             */
/*   Updated: 2022/02/20 21:59:22 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_ext(char *fname)
{
	int		i;
	char	*ext;

	i = 0;
	while (fname[i])
		i++;
	ext = &(*(fname + i - 4));
	i = 0;
	if (ext[0] == '.' && ext[1] == 'b' \
		&& ext[2] == 'e' && ext[3] == 'r')
		return ;
	else
	{
		printf("Error\nCheck the file extension!\n");
		exit(EXIT_FAILURE);
	}
}

void	map_init(t_map *map)
{
	map->player = 0;
	map->collect = 0;
	map->exit = 0;
	map->hauteur = 0;
	map->largeur = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->steps = 0;
	map->sliver = 0;
	map->count = 0;
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac == 2)
	{
		check_ext(av[1]);
		fd = open (av[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error while opening the map file");
			exit(EXIT_FAILURE);
		}
		map_init(&map);
		valid_map(&map, fd, av[1]);
		map.mlx = mlx_init();
		map.mlx_win = mlx_new_window(map.mlx, map.largeur * 48, \
		map.hauteur * 48, "So_long");
		game_init(&map);
		mlx_loop_hook(map.mlx, &yugi_update, &map);
		mlx_hook(map.mlx_win, 17, 0, destroy_window, &map);
		mlx_hook(map.mlx_win, 2, (1L << 0), key_hook, &map);
		mlx_loop(map.mlx);
		free(map.mlx);
	}
	ft_printf("Usage: ./so_long_bonus some_map.ber\n");
}
