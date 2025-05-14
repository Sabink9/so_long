/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:37:37 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/14 19:07:27 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <mlx.h>
#include "../get_next_line/get_next_line.h"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
}	t_map;

typedef struct s_pathcheck
{
	int	collect_found;
	int	exit_found;
	int	enemy_found;
}	t_pathcheck;

typedef struct s_imgs {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*ennemy;
}	t_imgs;


//map parse
void	fill_sprites_map(char **map, void *mlx, void *win, t_imgs *imgs);


//map acces
int	is_map_playable(t_map *map, t_pathcheck *check);
char	**copy_map(t_map *map);


#endif