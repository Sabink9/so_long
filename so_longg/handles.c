/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:23:34 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/15 22:42:35 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_cases(t_data *data, int x, int y)
{
	int	ex;
	int	ey;

	if (data->mapc[y][x] == 'N')
		exit(0);
	if (data->mapc[y][x] == 'C')
	{
		data->mapc[y][x] = '0';
		data->map->collected++;
	}
	ex = data->map->exit_x;
	ey = data->map->exit_y;
	if (data->map->collected == data->map->collectibles)
	{
		data->mapc[ey][ex] = 'O';
		mlx_put_image_to_window(data->mlx, data->win, data->imgs->open_exit, ex
				* 64, ey * 64);
	}
	if (data->mapc[y][x] == 'O')
		exit(0);
}

int	handle_key(int keycode, void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data *)param;
	if (keycode == 65307) // ESC
		exit(0);
	x = data->map->player_x;
	y = data->map->player_y;
	right(keycode, data, x, y);
	left(keycode, data, x, y);
	up(keycode, data, x, y);
	down(keycode, data, x, y);
	return (0);
}

int	handle_close(void *mlx)
{
	mlx_destroy_window(mlx, mlx);
	exit(0);
	return (0);
}
