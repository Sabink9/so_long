/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:32:30 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/18 16:26:18 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	right(int keycode, t_data *data, int x, int y)
{
	if (keycode == 'd')
	{
		if (data->mapc[y][x + 1] != '1')
		{
			data->map->player_x += 1;
			if (data->mapc[y][x] != 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->imgs->floor,
					x * 64, y * 64);
			else
				mlx_put_image_to_window(data->mlx, data->win,
					data->imgs->c_exit, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs->p_right, (x + 1) * 64, y * 64);
			handle_cases(data, x + 1, y);
			return (1);
		}
	}
	return (0);
}

int	left(int keycode, t_data *data, int x, int y)
{
	if (keycode == 'a')
	{
		if (data->mapc[y][x - 1] != '1')
		{
			data->map->player_x -= 1;
			if (data->mapc[y][x] != 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->imgs->floor,
					x * 64, y * 64);
			else
				mlx_put_image_to_window(data->mlx, data->win,
					data->imgs->c_exit, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs->p_left, (x - 1) * 64, y * 64);
			handle_cases(data, x - 1, y);
			return (1);
		}
	}
	return (0);
}

int	up(int keycode, t_data *data, int x, int y)
{
	if (keycode == 'w')
	{
		if (data->mapc[y - 1][x] != '1')
		{
			data->map->player_y -= 1;
			if (data->mapc[y][x] != 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->imgs->floor,
					x * 64, y * 64);
			else
				mlx_put_image_to_window(data->mlx, data->win,
					data->imgs->c_exit, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->imgs->p_up,
				x * 64, (y - 1) * 64);
			handle_cases(data, x, y - 1);
			return (1);
		}
	}
	return (0);
}

int	down(int keycode, t_data *data, int x, int y)
{
	if (keycode == 's')
	{
		if (data->mapc[y + 1][x] != '1')
		{
			data->map->player_y += 1;
			if (data->mapc[y][x] != 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->imgs->floor,
					x * 64, y * 64);
			else
				mlx_put_image_to_window(data->mlx, data->win,
					data->imgs->c_exit, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs->p_down, x * 64, (y + 1) * 64);
			handle_cases(data, x, y + 1);
			return (1);
		}
	}
	return (0);
}

int	launch_game(char **mapc, t_imgs *imgs, t_map *map)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, map->width * 64, map->height * 64,
			"BABINSKI");
	if (!data.win)
	{
		free(data.mlx);
		return (1);
	}
	data.map = map;
	data.imgs = imgs;
	data.mapc = mapc;
	data.moves = 0;
	fill_sprites_map(mapc, data.mlx, data.win, imgs);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	free_images(&data);
	return (0);
}
