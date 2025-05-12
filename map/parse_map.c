/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:43:09 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/12 16:36:54 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>

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
				(*has_e)++;
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
			if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C' && c != 'N')
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
		return (printf("Error\nNot a possible character\n"), 0);
	if (has_p != 1)
		return (printf("Error\nNeed exactly 1 player (P)\n"), 0);
	if (has_e != 1)
		return (printf("Error\nNeed exactly 1 exit (E)\n"), 0);
	if (has_c < 1)
		return (printf("Error\nNeed at least 1 collectible (C)\n"), 0);
	return (1);
}

void	fill_grid(t_map *map, int fd)
{
	char	*line;
	int		y;

	y = 0;
	map->grid = malloc(sizeof(char *) * (1024));
	if (!map->grid)
		exit(1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->grid[y] = line;
		y++;
		line = get_next_line(fd);
	}
	map->grid[y] = NULL;
}

int	check_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
			{
				if (map->grid[y][x] != '1')
				{
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	parse_map(t_map *map, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(printf("Error\nCan't open map\n"));
	map->height = count_lines(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map->width = count_rows(fd);
	close(fd);
	if (map->width == -1)
		exit(printf("Error\nMap is not rectangular\n"));
	fd = open(argv[1], O_RDONLY);
	fill_grid(map, fd);
	close(fd);
	if (!validate_map(map))
		exit(1);
	if (!check_walls(map))
		exit(printf("Error\nInvalid walls\n"));
}

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
			free(map->grid[i++]);
		free(map->grid);
	}
}


int	main(int argc, char **argv)
{
	t_map	map;
	t_pathcheck check;

	if (argc == 2)
	{
		parse_map(&map, argv);
		printf("Map loaded successfully!\n");
		printf("Map size: %dx%d\n", map.width, map.height);
		printf("Player position: (%d, %d)\n", map.player_x, map.player_y);
		is_map_playable(&map, &check);
		free_map(&map);
	}
	else
		printf("Map not found");
	return (0);
}
