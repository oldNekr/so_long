/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:31:21 by lrosby            #+#    #+#             */
/*   Updated: 2021/12/06 18:29:39 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize != 0)
		while (++i < (dstsize - 1) && src[i] != '\0')
			dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen_gnl(src));
}

char	*ft_substr_gnl(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen_gnl(s))
	{
		str = (char *) malloc(1);
		*str = '\0';
		return (str);
	}
	if ((ft_strlen_gnl(s) - start) < len)
		len = ft_strlen_gnl(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	ft_strlcpy_gnl(str, s + start, len + 1);
	str[len] = '\0';
	return (str);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*adr;
	size_t	size;

	size = ft_strlen_gnl(s1);
	adr = malloc(size + 1);
	if (!adr)
		return (adr);
	ft_strlcpy_gnl(adr, s1, size + 1);
	return (adr);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
