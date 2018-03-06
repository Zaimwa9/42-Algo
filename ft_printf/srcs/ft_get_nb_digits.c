/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:51:36 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/04 12:51:38 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_get_nb_digits(long long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		if (n < -base)
		{
			n = n / base;
			i++;
		}
		n = -n;
	}
	while (n >= 1)
	{
		i++;
		n = n / base;
	}
	return (i);
}
