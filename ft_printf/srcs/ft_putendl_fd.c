/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:49:04 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/14 18:52:45 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!(s))
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
