/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:05:46 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/29 19:05:48 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		pf_convert_s(t_caracs *input)
{
	if (ft_strcmp(input->size, "l") == 0)
		input->type = "wchar_t *";
	else
		input->isdef = 0;
	return (1);
}

int		pf_convert_c(t_caracs *input)
{
	if (ft_strcmp(input->size, "l") == 0)
		input->type = "wchar_t";
	else
		input->isdef = 0;
	return (1);
}

int		pf_convert_capsc(t_caracs *input)
{
	if (ft_strcmp(input->size, "notdef") != 0)
		input->isdef = 0;
	return (1);
}

int		pf_percent(t_caracs *input)
{
	input->type = "char";
	input->conv = '%';
	return (1);
}

int		pf_convidx(t_caracs *input)
{
	input->conv = g_conv[0][input->convidx][0];
	input->type = g_conv[1][input->convidx];
	return (1);
}
