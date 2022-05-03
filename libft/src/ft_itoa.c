/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:58:07 by lrosby            #+#    #+#             */
/*   Updated: 2021/10/20 19:58:27 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int static	ft_digit_length(int n)
{
	size_t	length;

	if (n == 0)
		return (1);
	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;

	size = ft_digit_length(n);
	if (n < 0)
		size++;
	str = malloc(size + 1);
	if (!str)
		return (str);
	if (n < 0)
		str[0] = '-';
	str[size--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		if (n > 0)
			str[size] = '0' + n % 10;
		else
			str[size] = '0' - n % 10;
		size--;
		n = n / 10;
	}
	return (str);
}
