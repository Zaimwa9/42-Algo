/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:39:32 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/23 14:37:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_csqrt(int nb)
{
	int		i;

	i = 1;
	if (nb > 0)
		while (i * i < nb)
			i++;
	else
		i = 0;
	return (i);
}
