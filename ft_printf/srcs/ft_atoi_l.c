/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:35:17 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/17 16:35:21 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

long	ft_atoi_l(const char *str)
{
	long	result;
	int		flag;

	result = 0;
	flag = 1;
	while (*str == '\t' || *str == '\n' || *str == 32 || *str == '\r' \
			|| *str == '\b' || *str == '\v' || *str == '\a' || *str == '\f')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) == 1 && (*str))
		result = result * 10 + (*str++ - 48);
	return (result * flag);
}
