#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	int		line_num;

	fd = open("texto.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	line_num = 1;
	str = get_next_line(fd);
	while (str)
	{
		printf("[Linea %d]: %s", line_num, str);
		free(str);
		line_num++;
		str = get_next_line(fd);
	}
	printf("\n--- Fin de lectura ---\n");
	close(fd);
	return (0);
}