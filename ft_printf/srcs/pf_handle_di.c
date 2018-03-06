/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:03:47 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/29 19:03:48 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		pf_handle_di(t_caracs *input)
{
	int		nb_char;

	input->raw_len = ft_strlen(input->raw_output);
	nb_char = input->raw_len - input->isneg;
	nb_char = nb_char < input->prec ? input->prec : nb_char;
	if ((input->plus == 1 || input->isneg == 1 || input->space == 1)
		&& nb_char >= input->width)
		nb_char += 1;
	nb_char = nb_char < input->width ? input->width : nb_char;
	input->length = nb_char;
	if (input->minus == 0)
		pf_fill_output_di(input);
	else
		pf_fill_minus_di(input);
	return (1);
}

void	pf_add_sign(t_caracs *input, int i)
{
	if (input->plus == 1)
		input->final[i] = '+';
	else if (input->space == 1)
		input->final[i] = ' ';
	else if (input->isneg == 1)
		input->final[i] = '-';
}

void	pf_fill_minus_di(t_caracs *input)
{
	int		i;
	int		j;

	i = input->length;
	if (!((input->final) = ft_strnew(i)))
		ft_exit();
	pf_add_sign(input, 0);
	j = input->prec > (input->raw_len - input->isneg) ? input->prec -
		input->raw_len + input->isneg : 0;
	ft_strcpy(&input->final[input->isneg + j + input->plus],
		&input->raw_output[input->isneg]);
	while (j > 0)
		input->final[input->isneg + input->plus + j-- - 1] = '0';
	while (!(input->final[--i]))
		input->final[i] = input->padchar;
}

void	pf_fill_output_di(t_caracs *input)
{
	int		i;
	int		j;

	i = input->length;
	if (!((input->final) = ft_strnew(i)))
		ft_exit();
	if (input->isrelou == 0)
		ft_strcpy(&input->final[i - input->raw_len + input->isneg],
		&input->raw_output[input->isneg]);
	j = input->prec > (input->raw_len - input->isneg) ? input->prec -
	input->raw_len + input->isneg : 0;
	pf_add_sign(input, i - input->raw_len - j - 1 + input->isneg);
	while (j > 0)
		input->final[i - input->raw_len - j-- + input->isneg] = '0';
	if (input->width > 0 && input->width > input->prec &&
		input->width > input->raw_len - input->isneg)
	{
		j = 0;
		while (!(input->final[j]) && j < input->width)
			input->final[j++] = ' ';
	}
}
