/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:23:34 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/18 16:41:40 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	return_sprite_error(t_imgs *imgs, void *mlx)
{
	if (!imgs || !mlx)
		return ;
	if (imgs->wall)
		mlx_destroy_image(mlx, imgs->wall);
	if (imgs->floor)
		mlx_destroy_image(mlx, imgs->floor);
	if (imgs->colle)
		mlx_destroy_image(mlx, imgs->colle);
	if (imgs->c_exit)
		mlx_destroy_image(mlx, imgs->c_exit);
	if (imgs->open_exit)
		mlx_destroy_image(mlx, imgs->open_exit);
	if (imgs->ennemy)
		mlx_destroy_image(mlx, imgs->ennemy);
	if (imgs->p_up)
		mlx_destroy_image(mlx, imgs->p_up);
	if (imgs->p_down)
		mlx_destroy_image(mlx, imgs->p_down);
	if (imgs->p_right)
		mlx_destroy_image(mlx, imgs->p_right);
	if (imgs->p_left)
		mlx_destroy_image(mlx, imgs->p_left);
	exit(ft_printf("Error\nErreur de chargement des images\n"));
}

void	handle_cases(t_data *data, int x, int y)
{
	int	ex;
	int	ey;

	if (data->mapc[y][x] == 'N')
		free_and_exit(data, "Game Over : Le Jarl vous a eu", 0);
	else if (data->mapc[y][x] == 'O')
		free_and_exit(data, "Vous êtes sorti du Babinski", 0);
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
	if (keycode == 65307)
		handle_close(data);
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
	free_images(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_copy(data->mapc);
	free_map(data->map);
	exit(0);
	return (0);
}
