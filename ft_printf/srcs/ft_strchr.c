/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:55:32 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/12 17:22:58 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s))
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if ((char)*s == '\0' && c == 0)
		return ((char*)s);
	return ((char*)NULL);
}
