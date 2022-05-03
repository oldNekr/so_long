/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:30:41 by lrosby            #+#    #+#             */
/*   Updated: 2021/12/06 16:30:48 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*n_finder(char *line)
{
	size_t	i;

	if (!line)
		return (NULL);
	i = -1;
	while (line[++i] != 0)
		if (line[i] == '\n')
			return (&line[i]);
	return (NULL);
}

static char	*ft_remainder(int fd, char *buf, char *rem)
{
	long	file_read;
	char	*tmp;

	file_read = 1;
	while (file_read && !n_finder(rem))
	{
		file_read = read(fd, buf, BUFFER_SIZE);
		if (file_read < 0)
			return (NULL);
		buf[file_read] = '\0';
		if (!rem && file_read != 0)
			rem = ft_strdup_gnl(buf);
		else
		{
			tmp = rem;
			rem = ft_strjoin_gnl(tmp, buf);
			free(tmp);
		}
	}
	return (rem);
}

static char	*ft_reserve(char *line)
{
	char	*reserve;
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	reserve = ft_substr_gnl(line, i + 1, ft_strlen_gnl(line) - i - 1);
	if (*reserve == '\0')
	{
		free(reserve);
		reserve = NULL;
	}
	line[i + 1] = '\0';
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*line;
	char		*buf;

	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = ft_remainder(fd, buf, rem);
	if (!line)
	{
		free(buf);
		return (NULL);
	}
	rem = ft_reserve(line);
	free(buf);
	buf = NULL;
	return (line);
}
