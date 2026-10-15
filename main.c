#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("texto.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
    str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}