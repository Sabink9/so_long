#include "map.h"
#include <stdio.h>

char	**copy_map(t_map *map)
{
	int	i;
	char	**copy;

	i = 0;
	while (map->grid[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map->grid[i])
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy)
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	dfs(char **map, int x, int y, t_pathcheck *check)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0')
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		check->collect_found++;
	if (map[y][x] == 'E')
		check->exit_found = 1;
	if (map[y][x] == 'N')
	{
		check->enemy_found = 1;
		return ;
	}
	map[y][x] = 'V';
	dfs(map, x + 1, y, check);
	dfs(map, x - 1, y, check);
	dfs(map, x, y + 1, check);
	dfs(map, x, y - 1, check);
}



int	is_map_playable(t_map *map, t_pathcheck *check)
{
	char **copy = copy_map(map);
	check->collect_found = 0;
	check->exit_found = 0;
	check->enemy_found = 0;

	dfs(copy, map->player_x, map->player_y, check);
	if (!check->exit_found)
	{
		printf("La sortie n'est pas atteignable.\n");
		return (0);
	}
	else if (check->collect_found != map->collectibles)
	{
		printf("Il reste des collectibles inaccessibles.\n");
		return (0);
	}
	else
	{
		printf("Chemin valide !\n");
		return (1);
	}
}
