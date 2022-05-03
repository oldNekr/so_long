/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:46:25 by lrosby            #+#    #+#             */
/*   Updated: 2021/10/16 01:46:27 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*last;

	index = 0;
	last = NULL;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			last = (char *)(s + index);
		index++;
	}
	if (s[index] == (char)c)
		return ((char *)(s + index));
	return (last);
}
