/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_xo_testers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:04:09 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/29 19:04:10 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		pf_xo_tester(t_caracs *input, int j)
{
	if ((input->conv == 'x' || input->conv == 'X') &&
		input->raw_output[0] == '0' && input->raw_len == 1 &&
		input->final[j] == '0' && input->zero == 0 && input->hasdot == 1 &&
		input->hash == 0 && input->zero == 0 && input->width > 0)
	{
		return (1);
	}
	else
		return (0);
}

int		pf_xo_tester2(t_caracs *input)
{
	if (input->isrelou == 0 || (input->isrelou == 1 && input->width > 1) ||
		(input->canczero == 0 && (input->conv == 'x' || input->conv == 'X')))
	{
		return (1);
	}
	else
		return (0);
}

int		pf_xo_tester3(t_caracs *input)
{
	if (input->hash == 1 && (input->conv == 'o' || input->conv == 'O') &&
		input->prec == -1 && input->width < 1 && input->raw_output[0] == '0')
	{
		return (1);
	}
	else
		return (0);
}

int		pf_xo_tester4(t_caracs *input, int j)
{
	if (input->width > 0 && input->width > input->prec &&
		input->width >= input->raw_len + j)
	{
		return (1);
	}
	else
		return (0);
}

void	pf_p_hash(t_caracs *input)
{
	input->final[0] = '0';
	input->final[1] = 'x';
}
