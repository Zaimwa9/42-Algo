/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:06:23 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/11 18:06:24 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		pf_convert_d(t_caracs *input)
{
	if (ft_strcmp(input->size, "l") == 0)
		input->type = "long";
	if (ft_strcmp(input->size, "ll") == 0)
		input->type = "long long";
	if (ft_strcmp(input->size, "h") == 0)
		input->type = "short";
	if (ft_strcmp(input->size, "hh") == 0)
		input->type = "intchar";
	if (ft_strcmp(input->size, "j") == 0)
		input->type = "intmax_t";
	if (ft_strcmp(input->size, "z") == 0)
		input->type = "ssize_t";
	return (1);
}

int		pf_convert_oux(t_caracs *input)
{
	if (ft_strcmp(input->size, "l") == 0)
		input->type = "unsigned long";
	if (ft_strcmp(input->size, "ll") == 0)
		input->type = "unsigned long long";
	if (ft_strcmp(input->size, "h") == 0)
		input->type = "unsigned short";
	if (ft_strcmp(input->size, "hh") == 0)
		input->type = "unsigned char";
	if (ft_strcmp(input->size, "j") == 0)
		input->type = "uintmax_t";
	if (ft_strcmp(input->size, "z") == 0)
		input->type = "size_t";
	return (1);
}

int		pf_convert_real_u(t_caracs *input)
{
	if (ft_strcmp(input->size, "l") == 0)
		input->type = "unsigned long";
	if (ft_strcmp(input->size, "ll") == 0)
		input->type = "unsigned long long";
	if (ft_strcmp(input->size, "h") == 0)
		input->type = "unsigned long";
	if (ft_strcmp(input->size, "hh") == 0)
		input->type = "unsigned char";
	if (ft_strcmp(input->size, "j") == 0)
		input->type = "uintmax_t";
	if (ft_strcmp(input->size, "z") == 0)
		input->type = "size_t";
	return (1);
}
