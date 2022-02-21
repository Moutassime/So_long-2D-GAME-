/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:00:13 by eseiv             #+#    #+#             */
/*   Updated: 2022/02/20 22:00:15 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_consistency(t_map *map)
{
	int	len;
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map->field[++i])
	{
		j = -1;
		len = 0;
		while (map->field[i][++j] != '\n' && map->field[i][j])
			len++;
		if (len != map->largeur)
		{
			ft_printf("Error\nInconsistent map!\n");
			free(map->field);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_walls(t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->largeur)
	{
		if (map->field[0][x] != '1' || map->field[map->hauteur - 1][x] != '1')
		{
			ft_printf("Error\nThe walls are not placed properly!\n");
			free(map->field);
			exit(EXIT_FAILURE);
		}
	}
	x = -1;
	while (++x < map->hauteur)
	{
		if (map->field[x][0] != '1' || map->field[x][map->largeur - 1] != '1')
		{
			ft_printf("Error\nThe walls are not placed properly!\n");
			free(map->field);
			exit(EXIT_FAILURE);
		}
	}
}

void	helper(t_map *map, int i, int j)
{
	if (map->field[i][j] != '0'
		&& map->field[i][j] != 'P'
		&& map->field[i][j] != '1'
		&& map->field[i][j] != 'C'
		&& map->field[i][j] != 'E'
		&& map->field[i][j] != 'S')
	{
		ft_printf("Error\nInvalid character in the map!\n");
		free(map->field);
		exit(EXIT_FAILURE);
	}
	if (map->field[i][j] == 'P')
	{
		map->player++;
		map->p_x = i;
		map->p_y = j;
	}
	else if (map->field[i][j] == 'E')
		map->exit++;
	else if (map->field[i][j] == 'C')
		map->collect++;
	else if (map->field[i][j] == 'S')
		map->sliver++;
}

void	check_content(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->hauteur)
	{
		j = -1;
		while (++j < map->largeur)
			helper(map, i, j);
	}
	if (map->player != 1 || map->sliver == 0 \
		|| map->exit == 0 || map->collect == 0)
	{
		if (map->player != 1)
			ft_printf("Error\nNumber of players is inconvenient!\n");
		if (map->sliver == 0)
			ft_printf ("Error\nThe map need at least one enemy!");
		if (map->exit == 0)
			ft_printf("Error\nThe exit is missing!\n");
		if (map->collect == 0)
			ft_printf("Error\nNo collectables in the map!\n");
		free(map->field);
		exit(EXIT_FAILURE);
	}
}

int	valid_map(t_map *map, int fd, char *av)
{
	int		i;
	char	*leak;

	i = 0;
	leak = get_next_line(fd);
	while (leak && ++map->hauteur)
	{
		free(leak);
		leak = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (perror("Error while closing the file"), exit(EXIT_FAILURE), 0);
	map->field = (char **)malloc(sizeof(char *) * (map->hauteur + 1));
	if (!map->field)
		exit(EXIT_FAILURE);
	fd = open (av, O_RDONLY);
	while (i < map->hauteur)
		map->field[i++] = get_next_line(fd);
	close (fd);
	i = 0;
	while (i < map->field[0][i])
		i++;
	map->largeur = i;
	map->field[map->hauteur] = 0;
	return (check_consistency(map), check_walls(map), check_content(map), 0);
}
