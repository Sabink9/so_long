/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:37:37 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/12 15:34:10 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
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

//map parse


//map acces
int	is_map_playable(t_map *map, t_pathcheck *check);
char	**copy_map(t_map *map);


#endif