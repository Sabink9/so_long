#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


typedef struct	s_map
{
    char	**grille;
    int		largeur;
    int		longeur;
    int		player_x;
    int		player_y;
    int		collectibles;

}	t_map;

 #endif