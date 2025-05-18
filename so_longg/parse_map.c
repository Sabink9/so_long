/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:00:23 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/18 17:58:30 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(int fd)
{
	int		height;
	char	*line;

	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (height);
}

int	count_rows(int fd)
{
	int		first_line_width;
	int		current_width;
	char	*line;

	first_line_width = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		current_width = ft_strlen(line);
		if (first_line_width == -1)
			first_line_width = current_width;
		else if (current_width != first_line_width)
		{
			free(line);
			free_remaining_lines(fd);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (first_line_width);
}

void	check_elem(t_map *map, int *has_p, int *has_e, int *has_c)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				(*has_p)++;
			}
			else if (map->grid[y][x] == 'E')
				check_exit(map, has_e, x, y);
			else if (map->grid[y][x] == 'C')
				(*has_c)++;
			x++;
		}
		y++;
	}
	map->collectibles = (*has_c);
}

int	check_non_elements(t_map *map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C'
				&& c != 'N')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	int	has_e;
	int	has_p;
	int	has_c;

	has_e = 0;
	has_p = 0;
	has_c = 0;
	check_elem(map, &has_p, &has_e, &has_c);
	if (!check_non_elements(map))
		return (ft_printf("Error\nNot a possible character\n"), 0);
	if (has_p != 1)
		return (ft_printf("Error\nNeed exactly 1 player (P)\n"), 0);
	if (has_e != 1)
		return (ft_printf("Error\nNeed exactly 1 exit (E)\n"), 0);
	if (has_c < 1)
		return (ft_printf("Error\nNeed at least 1 collectible (C)\n"), 0);
	return (1);
}
