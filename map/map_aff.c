#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

int	main()
{
	int	fd = open("map.ber", O_RDONLY);
	char	*line;

	if (fd == -1)
	{
		printf("Error !");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}