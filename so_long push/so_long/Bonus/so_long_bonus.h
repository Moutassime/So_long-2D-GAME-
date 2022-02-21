/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:59:29 by eseiv             #+#    #+#             */
/*   Updated: 2022/02/20 21:59:30 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	char	**field;
	int		player;
	int		exit;
	int		collect;
	int		sliver;
	int		p_x;
	int		p_y;
	int		hauteur;
	int		largeur;
	int		img_hauteur;
	int		img_largeur;
	int		steps;
	void	*texture_yugi;
	void	*texture_path;
	void	*texture_wall;
	void	*texture_bdragon;
	void	*texture_exit;
	void	*texture_sliver;
	void	*texture_black;
	char	direction;
	int		count;
}	t_map;

int		valid_map(t_map *map, int fd, char *av);
void	game_init(t_map *map);
void	map_render(t_map *map, int i, int j);
int		key_hook(int key_code, t_map *map);
int		destroy_window(t_map *map);
int		yugi_update(t_map *map);
char	*ft_itoa(int n);
void	free_all(t_map *map);
#endif
