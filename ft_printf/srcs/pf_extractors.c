/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_extractors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:03:06 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/29 19:03:15 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		pf_find_conv(const char *fmt, t_caracs *input)
{
	int		i;

	i = 0;
	while (fmt[i])
	{
		while (ft_isalpha(fmt[i]) == 0 && (fmt[i]))
			if (fmt[i++] == '%')
				return (pf_percent(input));
		if (ft_isalpha(fmt[i]) > 0 && pf_issize(&fmt[i], 0) >= 0)
		{
			input->size = g_sizes[0][pf_issize(&fmt[i], 0)];
			i = i + ft_strlen(input->size);
		}
		if (ft_isalpha(fmt[i]) > 0 &&
			(input->convidx = pf_issize(&fmt[i++], 1)) >= 0)
			return (pf_convidx(input));
		return (-1);
	}
	return (-1);
}

int		pf_find_opts(const char *format, t_caracs *input)
{
	int		i;

	i = 0;
	while (format[i] != input->conv && format[i] != '.')
	{
		while (ft_isdigit(format[i]) > 0 && format[i] != '0')
			return (-1);
		if (format[i] == ' ')
			input->space = 1;
		if (format[i] == '#')
			input->hash = 1;
		if (format[i] == '-')
			input->minus = 1;
		if (format[i] == '+')
			input->plus = 1;
		if (format[i] == '0')
			input->zero = 1;
		i++;
	}
	if (input->space + input->hash + input->minus + input->plus
		+ input->zero > 0)
		input->hasopt = 1;
	return (1);
}

void	pf_get_prec(const char *fmt, t_caracs *input, va_list ap)
{
	int		i;

	i = 0;
	while (fmt[i] != input->conv && ft_isalpha(fmt[i]) != 1)
	{
		if (fmt[i] == '.')
		{
			input->hasdot = 1;
			input->prec = 1;
			if (ft_isdigit(fmt[i + 1]) && fmt[i + 1] == '0' &&
				!(ft_isdigit(fmt[i + 2])))
			{
				input->canczero = 1;
				input->prec = -2;
			}
			else if (ft_isdigit(fmt[i + 1]) && input->prec > -2)
				input->prec = ft_atoi(&fmt[i + 1]);
			else if (fmt[i + 1] == '*')
				input->prec = va_arg(ap, int);
			else if (!(ft_isdigit(fmt[i + 1])))
				input->prec = -2;
			return ;
		}
		i++;
	}
}

int		pf_get_type(t_caracs *input)
{
	if (input->conv == 's' || input->conv == 'S')
		pf_convert_s(input);
	if (input->conv == 'p')
		input->isdef = 0;
	if (input->conv == 'd' || input->conv == 'i' || input->conv == 'D')
		pf_convert_d(input);
	if (input->conv == 'o' || input->conv == 'O' ||
			input->conv == 'u' || input->conv == 'x' || input->conv == 'X')
		pf_convert_oux(input);
	if (input->conv == 'U')
		pf_convert_real_u(input);
	if (input->conv == 'c')
		pf_convert_c(input);
	if (input->conv == 'C' || input->conv == 'S')
		pf_convert_capsc(input);
	return (1);
}

int		pf_get_width(const char *format, t_caracs *input, va_list ap)
{
	int		i;

	i = 0;
	while (format[i] == '#' || format[i] == ' ' || format[i] == '0' ||
		format[i] == '+' || format[i] == '-')
		i++;
	while (format[i] != input->conv && ft_isalpha(format[i]) != 1 &&
		format[i] != '.')
	{
		if (ft_isdigit(format[i]) > 0)
		{
			input->width = ft_atoi(&format[i]);
			return (1);
		}
		else if (format[i] == '*')
			input->width = va_arg(ap, int);
		i++;
	}
	return (0);
}
