/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_rework_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:03:56 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/29 19:03:57 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_rework_struct5(t_caracs *input)
{
	if (input->conv == 'x' || input->conv == 'X' || input->conv == 'o' ||
		input->conv == 'O' || input->conv == 'd' || input->conv == 'i' ||
		input->conv == 'D' || input->conv == 'u' || input->conv == 'U')
	{
		if (ft_strlen(input->raw_output) == 1 &&
			input->raw_output[0] == '0' && input->prec < -1)
		{
			input->isrelou = 1;
			input->hash = input->conv == 'x' ? 0 : input->hash;
			if (input->conv == 'o')
				input->raw_output[0] = ' ';
		}
	}
	if ((input->conv == 'o' || input->conv == 'O') &&
		(input->raw_output[0] == '0' || input->raw_output[0] == ' '))
		input->hash = 0;
}

void	pf_rework_struct4(t_caracs *input)
{
	if (input->conv == 'C' || input->conv == 'S')
		if (input->hasopt == 1 && input->minus == 0)
			input->isdef = 0;
	if (input->conv == '%' && input->prec == 0)
		input->prec = 1;
	if ((input->conv == 'x' || input->conv == 'X') &&
		ft_strlen(input->raw_output) == 1 && input->raw_output[0] == '0')
	{
		input->hash = 0;
	}
	pf_rework_struct5(input);
}

void	pf_rework_struct3(t_caracs *input)
{
	if (input->conv == 's' || input->conv == 'S')
	{
		if (input->prec == -2)
			input->prec = 0;
		input->plus = 0;
		input->hash = 0;
		input->zero = 0;
	}
	if (input->conv == 'p')
	{
		input->isdef = input->hash == 1 ? input->isdef : 0;
		input->hash = 1;
	}
	if (input->conv == 'c')
	{
		input->isdef = (input->hasopt == 1 && input->minus == 0) ? 0 : 1;
		if (ft_strcmp(input->type, "wchar_t") != 0)
			input->prec = 1;
		input->plus = 0;
		input->space = 0;
		input->hash = 0;
	}
	pf_rework_struct4(input);
}

void	pf_rework_struct2(t_caracs *input)
{
	if (input->minus == 1 || input->prec > 0 || input->canczero == 1)
		input->zero = 0;
	if (input->conv != 'd' && input->conv != 'i' && input->conv != 'D')
	{
		input->space = 0;
		input->plus = 0;
	}
	if (input->conv != 'x' && input->conv != 'X' && input->conv != 'o' &&
		input->conv != 'O')
		input->hash = 0;
	if (input->zero == 1)
	{
		input->prec = input->width - input->isneg - input->plus - input->space;
		input->padchar = '0';
		if ((input->conv == 'x' || input->conv == 'X' || input->conv == 'p') &&
			input->hash == 1)
			input->prec += -2;
		if ((input->conv == 'o' || input->conv == 'O') && input->hash == 1)
			input->prec += -1;
	}
	pf_rework_struct3(input);
}

void	pf_rework_struct(t_caracs *input)
{
	if (input->prec == -2 && input->raw_output[0] != '0' &&
		(input->conv == 'o' || input->conv == 'O'))
		input->prec = -1;
	if (input->hasdot == 1 && (input->conv == 'O' || input->conv == 'o'))
		input->zero = 0;
	if (input->hash == 1 && input->prec > 0 && input->raw_output[0] != '0'
		&& (input->conv == 'O' || input->conv == 'o'))
		input->prec -= 1;
	if (input->hash == 1 && input->hasdot > 0 && input->raw_output[0] == '0'
		&& (input->conv == 'O' || input->conv == 'o'))
		input->prec = input->prec < 1 ? 1 : input->prec;
	if ((input->conv == 'd' || input->conv == 'i'))
	{
		if (input->raw_output[0] == '-')
		{
			input->plus = 0;
			input->isneg = 1;
			input->space = 0;
		}
	}
	pf_rework_struct2(input);
}
