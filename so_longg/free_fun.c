/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:41:12 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/18 17:58:39 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
			free(map->grid[i++]);
		free(map->grid);
		map->grid = NULL;
	}
}

void	free_copy(char **copy)
{
	int	i;

	i = 0;
	if (!copy)
		return ;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

void	free_images(t_data *data)
{
	if (!data || !data->imgs)
		return ;
	if (data->imgs->wall)
		mlx_destroy_image(data->mlx, data->imgs->wall);
	if (data->imgs->floor)
		mlx_destroy_image(data->mlx, data->imgs->floor);
	if (data->imgs->colle)
		mlx_destroy_image(data->mlx, data->imgs->colle);
	if (data->imgs->c_exit)
		mlx_destroy_image(data->mlx, data->imgs->c_exit);
	if (data->imgs->open_exit)
		mlx_destroy_image(data->mlx, data->imgs->open_exit);
	if (data->imgs->ennemy)
		mlx_destroy_image(data->mlx, data->imgs->ennemy);
	if (data->imgs->p_up)
		mlx_destroy_image(data->mlx, data->imgs->p_up);
	if (data->imgs->p_down)
		mlx_destroy_image(data->mlx, data->imgs->p_down);
	if (data->imgs->p_right)
		mlx_destroy_image(data->mlx, data->imgs->p_right);
	if (data->imgs->p_left)
		mlx_destroy_image(data->mlx, data->imgs->p_left);
}

void	free_and_exit(t_data *data, char *msg, int code)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free_images(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_copy(data->mapc);
	free_map(data->map);
	exit(code);
}

void	free_remaining_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}
