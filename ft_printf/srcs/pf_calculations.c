/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:15:59 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/09 12:16:01 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		pf_calculs(t_caracs *input)
{
	pf_rework_struct(input);
	if (input->conv == 'd' || input->conv == 'i' || input->conv == 'D' ||
		input->conv == 'u' || input->conv == 'U')
		pf_handle_di(input);
	if (input->conv == 's' || input->conv == 'S' || (input->conv == 'c' &&
		input->ischarnull == 0) || input->conv == '%' || input->conv == 'C')
		pf_handle_sbigs(input);
	if (input->conv == 'x' || input->conv == 'o' || input->conv == 'p' ||
		input->conv == 'X' || input->conv == 'O')
		pf_handle_xo(input);
	if (input->conv == 'c' && input->ischarnull == 1)
		pf_handle_cnull(input);
	return (1);
}

void	pf_fill_s_minus(t_caracs *input, int nb_char, int to_copy)
{
	int	i;

	i = 0;
	if (input->minus == 0)
	{
		ft_strncpy(&input->final[nb_char - to_copy],
			input->raw_output, to_copy);
		while (!input->final[i] && i < nb_char)
			input->final[i++] = input->padchar;
	}
	else if (input->minus == 1)
	{
		ft_strncpy(&input->final[0], input->raw_output, to_copy);
		while (!(input->final[--nb_char]) && nb_char >= 0)
			input->final[nb_char] = input->padchar;
	}
}

void	pf_handle_sbigs(t_caracs *input)
{
	int		nb_char;
	int		to_copy;

	if (input->raw_output == NULL)
	{
		input->final = ft_strdup("(null)");
		return ;
	}
	input->raw_len = ft_strlen(input->raw_output);
	if (input->prec >= 0)
		nb_char = input->raw_len < input->prec ? input->raw_len : input->prec;
	else
		nb_char = input->raw_len;
	to_copy = nb_char;
	nb_char = nb_char < input->width ? input->width : nb_char;
	if (!(input->final = ft_strnew(nb_char)))
		ft_exit();
	pf_fill_s_minus(input, nb_char, to_copy);
}
