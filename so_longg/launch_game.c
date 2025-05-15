/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:32:30 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/15 22:41:05 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	right(int keycode, t_data *data, int x, int y)
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
					data->imgs->closed_exit, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs->player_right, (x + 1) * 64, y * 64);
			handle_cases(data, x + 1, y);
		}
	}
}
void	left(int keycode, t_data *data, int x, int y)
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
					data->imgs->closed_exit, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win,
				data->imgs->player_left, (x - 1) * 64, y * 64);
			handle_cases(data, x - 1, y);
		}
	}
}

void	up(int keycode, t_data *data, int x, int y)
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
						data->imgs->closed_exit, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->imgs->player_up,
					x * 64, (y - 1) * 64);
			handle_cases(data, x, y - 1);
		}
	}
}
void	down(int keycode, t_data *data, int x, int y)
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
						data->imgs->closed_exit, x * 64, y * 64);
			mlx_put_image_to_window(data->mlx, data->win,
					data->imgs->player_down, x * 64, (y + 1) * 64);
			handle_cases(data, x, y + 1);
		}
	}
}

int	launch_game(char **mapc, t_imgs *imgs, t_map *map)
{
	void	*mlx;
	void	*win;
	t_data	data;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, map->width * 64, map->height * 64, "BABINSKI");
	if (!win)
		return (1);
	fill_sprites_map(mapc, mlx, win, imgs);
	data.map = map;
	data.imgs = imgs;
	data.mlx = mlx;
	data.win = win;
	data.mapc = mapc;
	mlx_key_hook(win, handle_key, &data);
	mlx_hook(win, 17, 0, handle_close, NULL);
	mlx_loop(mlx);
	return (0);
}
