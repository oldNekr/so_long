/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:06:08 by lrosby            #+#    #+#             */
/*   Updated: 2021/10/20 20:06:26 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void static	ft_print_recursive(int nb, int fd)
{
	if (nb == 0)
		return ;
	ft_print_recursive(nb / 10, fd);
	if (nb > 0)
		ft_putchar_fd('0' + nb % 10, fd);
	else
		ft_putchar_fd('0' - nb % 10, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
		ft_putchar_fd('-', fd);
	ft_print_recursive(nb, fd);
}
