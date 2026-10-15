/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbustos- <jbustos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 10:58:17 by jbustos-          #+#    #+#             */
/*   Updated: 2026/10/15 20:23:55 by jbustos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *c)
{
	int	count;

	count = 0;
	while (c[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	i = 0;
	if (!s1 && !s2)
        return (NULL);
	lens1 = 0;
	lens2 = 0;
	if (s1)
		lens1 = ft_strlen(s1);
	if (s2)
		lens2 = ft_strlen(s2);
	
	concat = malloc((lens1+ lens2 + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
	return (concat);
}
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	return (NULL);
}

char *ft_line(char const *s1)
{
	int		i;
	char 	*line;
	int		len;

	if (!s1 || s1[0] == '\0')
        return (NULL);
	i = 0;
	while(s1[i] != '\n' && s1[i] != '\0')
		i++;
	len = i;
	if (s1[i] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
        return (NULL);
	i = 0;
	while(s1[i] != '\n' && s1[i] != '\0')
	{
		line[i] = s1[i];
		i++;	
	}
	if (s1[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return(line);
}
