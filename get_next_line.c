/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbustos- <jbustos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 10:58:01 by jbustos-          #+#    #+#             */
/*   Updated: 2026/10/15 20:24:00 by jbustos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;
	int			n;
	char        *temp;
	char		*line;

	temp = NULL;
	buffer = malloc(11);
	if (!buffer)
		return(NULL);
printf("llego 1\n");
	while(!ft_strchr(save, '\n'))
	{
		n = read(fd, buffer, 10);
		if (n < 0)
		{
			printf("llego 2\n");
			free(buffer);
			return (NULL);
		}
		if (n == 0)
        	break;
		buffer[n] = '\0';
		temp = save;
		save = ft_strjoin(temp, buffer);
		if (temp)
			free(temp);
	}
	printf("llego 3\n");
	line = ft_line(save);
	free(buffer);
	return (line); 
}
