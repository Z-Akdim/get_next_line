/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:08:18 by zakdim            #+#    #+#             */
/*   Updated: 2019/12/22 12:46:27 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_chr(const char *s, int c)
{
	char		c3;
	char		*str;
	int			i;

	c3 = (char)c;
	str = (char *)s;
	i = 0;
	if (c3 == '\0')
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == c3)
			return (str + i);
		i++;
	}
	return (NULL);
}

char			*str_get(char *rest, int i, char **line)
{
	char		*ptr;

	while (rest[i])
	{
		if (rest[i] == '\n')
		{
			free(*line);
			*line = ft_substr(rest, 0, i);
			ptr = rest;
			rest = ft_strdup(rest + i + 1);
			free(ptr);
			return (rest);
		}
		i++;
	}
	if (rest[0] != '\0')
	{
		free(*line);
		*line = ft_substr(rest, 0, i);
		ptr = rest;
		free(ptr);
		return (NULL);
	}
	free(rest);
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*rest[4864];
	int			j;
	char		*ptr;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4864 || line == NULL
			|| !(buff = (char *)malloc((sizeof(char)) * BUFFER_SIZE + 1)))
		return (-1);
	*line = ft_strdup("\0");
	if (rest[fd] == NULL)
		if (!(rest[fd] = ft_calloc(1, 1)))
			return (-1);
	while ((!ft_chr(rest[fd], '\n')) && (j = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[j] = '\0';
		ptr = rest[fd];
		rest[fd] = ft_strjoin(rest[fd], buff);
		free(ptr);
	}
	free(buff);
	if (j < 0)
		free(rest[fd]);
	if (j < 0)
		return (-1);
	return (((rest[fd] = str_get(rest[fd], 0, line)) == NULL) ? 0 : 1);
}
