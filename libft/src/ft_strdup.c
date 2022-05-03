/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:42:10 by lrosby            #+#    #+#             */
/*   Updated: 2021/10/20 19:42:12 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*adr;
	size_t	size;

	size = ft_strlen(s1);
	adr = malloc(size + 1);
	if (!adr)
		return (adr);
	ft_strlcpy(adr, s1, size + 1);
	return (adr);
}
