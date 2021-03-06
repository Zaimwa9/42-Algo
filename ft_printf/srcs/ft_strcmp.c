/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:10:26 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/09 21:39:08 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((s1[i]) || (s2[i]))
	{
		if ((unsigned char)(s1[i]) != (unsigned char)(s2[i]))
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}
