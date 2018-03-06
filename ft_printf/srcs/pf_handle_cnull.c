/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_cnull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:03:37 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/29 19:03:39 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_copy_cnull(t_caracs *input, int nb_char, int to_copy)
{
	int		i;

	i = 0;
	if (input->minus == 0)
	{
		input->final[nb_char - to_copy] = '\0';
		while (!input->final[i] && i < nb_char - to_copy)
			input->final[i++] = input->padchar;
	}
	else if (input->minus == 1)
	{
		input->final[0] = '\0';
		while (!(input->final[--nb_char]) && nb_char > 0)
			input->final[nb_char] = input->padchar;
	}
}

void	pf_handle_cnull(t_caracs *input)
{
	int		nb_char;
	int		to_copy;

	if (input->raw_output == NULL)
	{
		input->final = ft_strdup("(null)");
		return ;
	}
	input->raw_len = ft_strlen(input->raw_output) + input->ischarnull;
	if (input->prec >= 0)
		nb_char = input->raw_len < input->prec ? input->raw_len : input->prec;
	else
		nb_char = input->raw_len;
	to_copy = nb_char;
	nb_char = nb_char < input->width ? input->width : nb_char;
	input->raw_len = input->ischarnull == 1 ? nb_char : input->raw_len;
	if (!(input->final = ft_strnew(nb_char)))
		ft_exit();
	pf_copy_cnull(input, nb_char, to_copy);
}
