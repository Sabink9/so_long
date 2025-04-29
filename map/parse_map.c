#include "map.h"

void	init_grille(t_map *map, char *fichier)
{
	int	fd;
	char	*ligne;
	int	i;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		exit_error("Erreur : Fichier Introuvable");
	map->longeur = 0;
	while ((ligne = get_next_line(fd)))
	{
		if (map->longeur == 0)
			map->largeur = ft_strlen(ligne) - 1;
		free(ligne);
		map->longeur++;
	}
	close(fd);

}

void	
{}

void	parse_map(char *filename, t_map *map)
{
	int	fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	get_next_line(fd);
}