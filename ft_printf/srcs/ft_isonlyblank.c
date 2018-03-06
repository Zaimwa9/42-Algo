/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:17:32 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/16 12:21:39 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_isonlyblank(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' || str[i] != '\t' || str[i] != '\r' || \
				str[i] != '\b' || str[i] != '\v' || str[i] != '\f')
			return (0);
		i++;
	}
	return (1);
}
