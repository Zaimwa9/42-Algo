/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:36:18 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/22 13:52:14 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(const char *err)
{
	if (err == NULL)
		ft_putstr("error\n");
	else if (ft_strcmp(err, "usage") == 0)
		ft_putstr("usage: ./fillit target_file\n");
}
