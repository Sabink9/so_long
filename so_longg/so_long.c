/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:43:09 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/19 20:21:08 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_grid(t_map *map, int fd)
{
	char	*line;
	int		y;

	y = 0;
	map->grid = malloc(sizeof(char *) * (map->height + 1));
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

int	parse_map(t_map *map, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nCan't open map\n"), 0);
	map->height = count_lines(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map->width = count_rows(fd);
	close(fd);
	if (map->width == -1)
		return (ft_printf("Error\nMap is not rectangular\n"), 0);
	fd = open(argv[1], O_RDONLY);
	fill_grid(map, fd);
	close(fd);
	if (!validate_map(map))
		return (0);
	if (!check_walls(map))
		return (ft_printf("Error\nInvalid walls\n"), 0);
	return (1);
}

int	is_map_valid(t_map *map, t_pathcheck *check, char ***mapc, char **argv)
{
	if (!parse_map(map, argv))
	{
		free_map(map);
		return (0);
	}
	*mapc = copy_map(map);
	if (!is_map_playable(map, check))
	{
		free_copy(*mapc);
		free_map(map);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_pathcheck	check;
	char		**mapc;
	t_imgs		imgs;

	map.grid = NULL;
	map.width = 0;
	map.height = 0;
	mapc = NULL;
	if (argc == 2)
	{
		if (!is_map_valid(&map, &check, &mapc, argv))
			return (1);
		map.collected = 0;
		launch_game(mapc, &imgs, &map);
		free_copy(mapc);
		free_map(&map);
	}
	else
		ft_printf("Map not found");
	return (0);
}
