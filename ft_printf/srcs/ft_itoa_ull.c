/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:36:33 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/17 16:36:34 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static size_t	ft_get_nb_digits_ull(uintmax_t n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		i++;
		n = n / base;
	}
	return (i);
}

char			*ft_itoa_ull(uintmax_t n)
{
	char				*dest;
	uintmax_t			nb;
	size_t				len;

	nb = n;
	len = ft_get_nb_digits_ull(nb, 10);
	if ((dest = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	dest[len] = '\0';
	while (len > 0)
	{
		dest[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (dest);
}
