/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:36:05 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/17 16:36:09 by wzaim            ###   ########.fr       */
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

char			*ft_itoa_base_ull(uintmax_t n, int base)
{
	char				*dest;
	uintmax_t			nb;
	size_t				len;

	if (base == 1)
	{
		if ((dest = (char*)malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		dest[1] = '\0';
		dest[0] = '1';
		return (dest);
	}
	if (base == 10)
		return (ft_itoa_ull(n));
	nb = n;
	len = ft_get_nb_digits_ull(nb, base);
	if ((dest = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	dest[len] = '\0';
	while (len > 0)
	{
		dest[--len] = (nb % base) + (nb % base > 9 ? 'a' - 10 : 48);
		nb = nb / base;
	}
	return (dest);
}
