/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:07:22 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/15 16:07:28 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		add_sign_itoa(long long n, char *dest)
{
	if (n < 0)
		dest[0] = '-';
}

char			*ft_itoa(long long n)
{
	char		*dest;
	long long	nb;
	size_t		len;

	nb = n;
	len = ft_get_nb_digits(nb, 10);
	if ((dest = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	dest[len] = '\0';
	if (n < 0)
	{
		if (n < -10)
		{
			dest[--len] = -(n % 10) + 48;
			n = n / 10;
		}
		nb = -n;
	}
	while (len > 0)
	{
		dest[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	add_sign_itoa(n, dest);
	return (dest);
}
