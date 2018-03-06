/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:47:37 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/13 18:43:17 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n <= 2147483647 && n >= -2147483648)
	{
		nb = n;
		if (n < 0)
		{
			ft_putchar('-');
			nb = -n;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		if (nb <= 9)
			ft_putchar(nb + '0');
	}
}
