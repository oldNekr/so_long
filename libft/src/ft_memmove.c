/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:48:18 by lrosby            #+#    #+#             */
/*   Updated: 2021/10/23 14:30:41 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*destin;
	unsigned char	*source;

	destin = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (destin == source)
		return (destin);
	if (source < destin)
	{
		index = len;
		while (index--)
			((unsigned char *)destin)[index] = ((unsigned char *)source)[index];
	}
	else
		ft_memcpy(dst, src, len);
	return (destin);
}
