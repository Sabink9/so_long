/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:43:09 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/15 22:37:01 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		exit(ft_printf("Error\nCan't open map\n"));
	map->height = count_lines(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map->width = count_rows(fd);
	close(fd);
	if (map->width == -1)
		exit(ft_printf("Error\nMap is not rectangular\n"));
	fd = open(argv[1], O_RDONLY);
	fill_grid(map, fd);
	close(fd);
	if (!validate_map(map))
		exit(1);
	if (!check_walls(map))
		exit(ft_printf("Error\nInvalid walls\n"));
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_pathcheck	check;
	char		**mapc;
	t_imgs		imgs;

	if (argc == 2)
	{
		parse_map(&map, argv);
		mapc = copy_map(&map);
		ft_printf("Map loaded successfully!\n");
		ft_printf("Map size: %dx%d\n", map.width, map.height);
		if (!is_map_playable(&map, &check))
		{
			free_copy(mapc);
			free_map(&map);
			return (0);
		}
		map.collected = 0;
		launch_game(mapc, &imgs, &map);
		free_copy(mapc);
		free_map(&map);
	}
	else
		ft_printf("Map not found");
	return (0);
}
