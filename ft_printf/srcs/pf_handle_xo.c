/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_xo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:05:37 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/29 19:05:38 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		pf_ishash(t_caracs *input)
{
	if (input->conv == 'x' || input->conv == 'X' || input->conv == 'p')
	{
		if (input->hash == 1)
			return (2);
		else
			return (0);
	}
	if (input->conv == 'o' || input->conv == 'O')
	{
		if (input->hash == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	pf_add_hash(t_caracs *input, int i)
{
	if ((input->conv == 'o' || input->conv == 'O') &&
		input->raw_output[0] == '0')
		return ;
	if (i >= 0)
	{
		if (input->hash == 1 && input->conv == 'p' && input->hasdot == 1 &&
			input->prec <= 2)
			pf_p_hash(input);
		else if (input->hash == 1 &&
			(input->conv == 'x' || input->conv == 'p' || input->conv == 'X'))
		{
			input->final[i - 1] = 'x';
			input->final[i - 2] = '0';
		}
		else if (input->hash == 1 && input->raw_output[0] != ' ' &&
			(input->conv == 'o' || input->conv == 'O') &&
				input->prec >= -1 && input->width > 1)
			input->final[i - 1] = '0';
		else if (input->hash == 1 && input->prec == -2 &&
			(input->conv == 'o' || input->conv == 'O'))
			input->final[i] = '0';
		else if (input->hash == 1 && input->raw_output[0] != ' ' &&
			(input->conv == 'o' || input->conv == 'O'))
			input->final[i - 1] = '0';
	}
}

void	pf_handle_xo(t_caracs *input)
{
	int		nb_char;

	input->raw_len = ft_strlen(input->raw_output);
	if (input->prec >= 0)
		nb_char = input->raw_len < input->prec ? input->prec : input->raw_len;
	else
		nb_char = input->raw_len;
	if (input->conv == 'x' || input->conv == 'p' || input->conv == 'X')
		nb_char = input->hash == 1 ? nb_char + 2 : nb_char;
	else if (input->conv == 'o' || input->conv == 'O')
		nb_char = input->hash == 1 ? nb_char + 1 : nb_char;
	if (input->hash == 1 && (input->conv == 'o' || input->conv == 'O')
		&& input->prec == -2)
		nb_char = nb_char - 1;
	if ((input->conv == 'x' || input->conv == 'X' || input->conv == 'p') &&
		input->hasdot == 1 && input->prec <= 0 && input->raw_output[0] == '0')
		nb_char += -1;
	nb_char = nb_char < input->width ? input->width : nb_char;
	if (!((input->final) = ft_strnew(nb_char)))
		ft_exit();
	(input->minus == 0) ?
		pf_fill_xo(input, nb_char) : pf_fill_minus_xo(input, nb_char);
	if (input->conv == 'X' && input->raw_output[0] != '0' && input->raw_len > 1)
		ft_strcapitalize(input->final);
}

void	pf_fill_xo(t_caracs *input, int nb_char)
{
	int		j;
	int		ishash;

	ishash = pf_ishash(input);
	if (pf_xo_tester3(input) == 1)
	{
		nb_char = nb_char - 1;
	}
	if (pf_xo_tester2(input) == 1)
		ft_strncpy(&input->final[nb_char - input->raw_len],
			input->raw_output, input->raw_len);
	j = input->prec > input->raw_len ? input->prec - input->raw_len : 0;
	pf_add_hash(input, nb_char - input->raw_len - j);
	while (j > 0)
		input->final[nb_char - input->raw_len - j--] = '0';
	j = input->hash == 1 ? ishash : 0;
	if (pf_xo_tester4(input, j) == 1)
	{
		j = 0;
		while (!(input->final[j]) && j <= nb_char)
			input->final[j++] = input->padchar;
		if (pf_xo_tester(input, j) == 1)
			input->final[j] = input->padchar;
	}
}

void	pf_fill_minus_xo(t_caracs *input, int nb_char)
{
	int		j;
	int		ishash;
	int		i;

	i = nb_char;
	if (input->conv == 'x' || input->conv == 'X' || input->conv == 'p')
		ishash = input->hash == 1 ? 2 : 0;
	if (input->conv == 'o' || input->conv == 'O')
		ishash = input->hash == 1 ? 1 : 0;
	pf_add_hash(input, ishash);
	j = input->prec > input->raw_len ? input->prec - input->raw_len : 0;
	ft_strncpy(&input->final[j + ishash], input->raw_output, input->raw_len);
	while (j > 0)
		input->final[ishash + --j] = '0';
	while (!(input->final[--i]) && i > 0)
		input->final[i] = ' ';
}
