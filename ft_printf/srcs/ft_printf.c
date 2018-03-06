/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:11:58 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/26 16:12:01 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*g_sizes[2][6];
char	*g_conv[2][15];

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	pf_init_globals();
	return (ft_printf_rec(format, 0, ap));
}

void	flag2free(t_caracs *input)
{
	if (input->raw_len <= 1 && (input->conv == 'x' || input->conv == 'X') &&
		input->raw_output[0] == '0' && input->hasdot == 1 &&
		input->prec <= -1 && input->width <= 1)
	{
		free(input->raw_output);
		free(input);
	}
	else
	{
		free(input->raw_output);
		free(input->final);
		free(input);
	}
}

void	flag0free(t_caracs *input, char **mystr)
{
	if (input->raw_len <= 1 && (input->conv == 'x' || input->conv == 'X') &&
		input->raw_output[0] == '0' && input->hasdot == 1 &&
		input->prec <= -1 && input->width <= 1)
	{
		free(mystr);
		free(input->raw_output);
		free(input);
	}
	else
	{
		free(mystr);
		free(input->raw_output);
		free(input->final);
		free(input);
	}
}

int		myfree(t_caracs *input, char **mystr, int flag)
{
	if (flag == 0)
		flag0free(input, mystr);
	if (flag == 1)
	{
		free(mystr);
		free(input);
	}
	if (flag == 2)
		flag2free(input);
	if (flag == 3)
	{
		free(*mystr);
		free(mystr);
	}
	return (1);
}
