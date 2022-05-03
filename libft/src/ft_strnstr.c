/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:27:55 by lrosby            #+#    #+#             */
/*   Updated: 2021/10/23 14:31:18 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		len_needle;

	if (*needle == '\0' || haystack == needle
		|| (len == 1 && *haystack == *needle))
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	len_needle = ft_strlen(needle);
	i = 0;
	while (haystack[i] && i <= (len - len_needle))
	{
		if (ft_strncmp(&haystack[i], needle, len_needle) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
