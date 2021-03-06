/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:30:26 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/14 15:33:49 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!(s) || !(f))
		return ;
	i = ft_strlen(s);
	while (i > 0)
	{
		f(j++, s++);
		i--;
	}
}
