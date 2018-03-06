/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:40:42 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/17 16:35:53 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_itoa_base(long long n, int base)
{
	char			*dest;
	long long		nb;
	size_t			len;

	if (base == 1)
	{
		if ((dest = (char*)malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		dest[1] = '\0';
		dest[0] = '1';
		return (dest);
	}
	if (base == 10)
		return (ft_itoa(n));
	nb = n >= 0 ? n : 4294967295 + 1 + n;
	len = ft_get_nb_digits(nb, base);
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
