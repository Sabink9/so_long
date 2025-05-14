#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "map.h"


void	fill_sprites_map(char **map, void *mlx, void *win, t_imgs *imgs)
{
	int	w;
	int	h;
	int	x;
	int	y;

	imgs->wall = mlx_xpm_file_to_image(mlx, "sprites/sprite_murs.xpm", &w, &h);
	imgs->floor = mlx_xpm_file_to_image(mlx, "sprites/sprite_sol.xpm", &w, &h);
	imgs->collectible = mlx_xpm_file_to_image(mlx, "sprites/sprite_ballon.xpm", &w, &h);
	imgs->exit = mlx_xpm_file_to_image(mlx, "sprites/sprite_open_door.xpm", &w, &h);
	imgs->ennemy = mlx_xpm_file_to_image(mlx, "sprites/sprite_secu.xpm", &w, &h);
	imgs->player = mlx_xpm_file_to_image(mlx, "sprites/sprite_face.xpm", &w, &h);

	if (!imgs->wall || !imgs->floor || !imgs->collectible || !imgs->exit || !imgs->ennemy || !imgs->player)
	{
		printf("Erreur de chargement des images\n");
		return;
	}
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			mlx_put_image_to_window(mlx, win, imgs->floor, x * 64, y * 64);
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, imgs->wall, x * 64, y * 64);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, imgs->player, x * 64, y * 64);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, imgs->collectible, x * 64, y * 64);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, imgs->exit, x * 64, y * 64);
			else if (map[y][x] == 'N')
				mlx_put_image_to_window(mlx, win, imgs->ennemy, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

