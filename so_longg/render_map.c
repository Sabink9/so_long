/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:36:13 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/17 18:22:18 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(t_map *map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map->grid[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map->grid[i])
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	dfs(char **map, int x, int y, t_pathcheck *check)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0')
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		check->collect_found++;
	if (map[y][x] == 'E')
		check->exit_found = 1;
	if (map[y][x] == 'N')
	{
		check->enemy_found = 1;
		return ;
	}
	map[y][x] = 'V';
	dfs(map, x + 1, y, check);
	dfs(map, x - 1, y, check);
	dfs(map, x, y + 1, check);
	dfs(map, x, y - 1, check);
}

int	is_map_playable(t_map *map, t_pathcheck *check)
{
	char	**copy;

	check->collect_found = 0;
	check->exit_found = 0;
	check->enemy_found = 0;
	copy = copy_map(map);
	dfs(copy, map->player_x, map->player_y, check);
	if (!check->exit_found)
	{
		ft_printf("Error\nLa sortie n'est pas atteignable.\n");
		free_copy(copy);
		return (0);
	}
	else if (check->collect_found != map->collectibles)
	{
		ft_printf("Error\nIl reste des collectibles inaccessibles.\n");
		free_copy(copy);
		return (0);
	}
	else
	{
		ft_printf("Chemin valide !\n");
		free_copy(copy);
		return (1);
	}
}

void	define_sprites(void *mlx, t_imgs *imgs)
{
	int	w;
	int	h;

	imgs->wall = mlx_xpm_file_to_image(mlx, "sprites/sprite_murs.xpm", &w, &h);
	imgs->floor = mlx_xpm_file_to_image(mlx, "sprites/sprite_sol.xpm", &w, &h);
	imgs->colle = mlx_xpm_file_to_image(mlx, "sprites/sprite_ballon.xpm", &w,
			&h);
	imgs->c_exit = mlx_xpm_file_to_image(mlx, "sprites/sprite_closed_door.xpm",
			&w, &h);
	imgs->open_exit = mlx_xpm_file_to_image(mlx, "sprites/sprite_open_door.xpm",
			&w, &h);
	imgs->ennemy = mlx_xpm_file_to_image(mlx, "sprites/sprite_secu.xpm", &w,
			&h);
	imgs->p_up = mlx_xpm_file_to_image(mlx, "sprites/sprite_dos.xpm", &w, &h);
	imgs->p_down = mlx_xpm_file_to_image(mlx, "sprites/sprite_face.xpm", &w,
			&h);
	imgs->p_right = mlx_xpm_file_to_image(mlx, "sprites/sprite_droite.xpm", &w,
			&h);
	imgs->p_left = mlx_xpm_file_to_image(mlx, "sprites/sprite_gauche.xpm", &w,
			&h);
	if (!imgs->wall || !imgs->floor || !imgs->colle || !imgs->c_exit
		|| !imgs->open_exit || !imgs->ennemy || !imgs->p_up || !imgs->p_down
		|| !imgs->p_right || !imgs->p_left)
		return_sprite_error(imgs, mlx);
}

void	fill_sprites_map(char **map, void *mlx, void *win, t_imgs *imgs)
{
	int	x;
	int	y;

	define_sprites(mlx, imgs);
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
				mlx_put_image_to_window(mlx, win, imgs->p_down, x * 64, y * 64);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, imgs->colle, x * 64, y * 64);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, imgs->c_exit, x * 64, y * 64);
			else if (map[y][x] == 'N')
				mlx_put_image_to_window(mlx, win, imgs->ennemy, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
