/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbustos- <jbustos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 10:58:01 by jbustos-          #+#    #+#             */
/*   Updated: 2026/11/21 17:54:08 by jbustos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_all(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

static char	*ft_read_save(int fd, char *save)
{
	char	*buffer;
	char	*temp;
	int		n;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_all(save, NULL));
	n = 1;
	while (!ft_strchr(save, '\n') && n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (ft_free_all(buffer, save));
		buffer[n] = '\0';
		temp = save;
		save = ft_strjoin(temp, buffer);
		if (temp)
			free(temp);
		if (!save)
			return (ft_free_all(buffer, NULL));
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	if (!line)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = ft_clean_save(save);
	return (line);
}
