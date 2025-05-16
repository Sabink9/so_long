/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:23:34 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/16 17:57:21 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_cases(t_data *data, int x, int y)
{
	int	ex;
	int	ey;

	if (data->mapc[y][x] == 'N' || data->mapc[y][x] == 'O')
	{
		if (data->mapc[y][x] == 'N')
			ft_printf("Game Over : Le Jarl vous a eu\n");
		else
			ft_printf("Vous etes sortie du Babinski\n");
		exit(0);	
	}
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
}

int	handle_key(int keycode, void *param)
{
	t_data	*data;
	int		moved;
	char	*str;

	data = (t_data *)param;
	moved = 0;
	if (keycode == 65307) // ESC
		exit(0);
	moved += right(keycode, data, data->map->player_x, data->map->player_y);
	moved += left(keycode, data, data->map->player_x, data->map->player_y);
	moved += up(keycode, data, data->map->player_x, data->map->player_y);
	moved += down(keycode, data, data->map->player_x, data->map->player_y);
	if (moved)
	{
		data->moves++;
		str = ft_itoa(data->moves);
		ft_printf("Moves: %s\n", str);
		mlx_put_image_to_window(data->mlx, data->win, data->imgs->wall, 0, 0);
		mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "Moves:");
		mlx_string_put(data->mlx, data->win, 30, 30, 0xFFFFFF, str);
		free(str);
	}
	return (0);
}

int	handle_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_copy(data->mapc);
	free_map(data->map);
	exit(0);
	return (0);
}
