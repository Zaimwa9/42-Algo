/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:39:38 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/16 16:38:32 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putstr(char const *s)
{
	size_t	i;
	size_t	size;

	if (!(s))
		return ;
	size = ft_strlen(s);
	i = 0;
	while (i < size)
		ft_putchar(s[i++]);
}
