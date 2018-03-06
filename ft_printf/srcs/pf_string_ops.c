/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:54:59 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/17 13:55:00 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		pf_add_null(char *dest, t_caracs *input, int p)
{
	int		to_copy;

	to_copy = input->length - input->ischarnull;
	if (input->minus == 1)
	{
		ft_strncpy(&dest[p + 1], &input->final[1], to_copy);
		dest[p] = '\0';
	}
	else if (input->minus == 0 && input->ischarnull == 1)
	{
		ft_strncpy(&dest[p], input->final, input->length - input->ischarnull);
		dest[p + input->length] = '\0';
	}
}

void		pf_copy_body(char *dest, t_caracs *input, int p)
{
	ft_strncpy(&dest[p], input->final, input->length - input->ischarnull);
	dest[p + input->length] = '\0';
}

void		pf_handle_copy(char *dest, t_caracs *input, int p)
{
	if (input->ischarnull == 1)
		pf_add_null(dest, input, p);
	else
		pf_copy_body(dest, input, p);
}

void		pf_get_length(t_caracs *input)
{
	if (input->raw_len <= 1 && (input->conv == 'x' || input->conv == 'X') &&
		input->raw_output[0] == '0' && input->hasdot == 1 &&
		input->prec <= -1 && input->width <= 1)
		input->length = 0;
	else if (input->raw_len > 1 && input->ischarnull == 1)
		input->length = input->raw_len;
	else
		input->length = ft_strlen(input->final) + input->ischarnull;
}

char		*pf_insert_str(t_caracs *input, const char *format, int p)
{
	int		to_del;
	int		i;
	int		size;
	char	*dest;

	i = input->conv == '%' ? 1 : 0;
	to_del = 1;
	pf_get_length(input);
	while (format[p + i++] != input->conv)
		to_del++;
	to_del = input->conv == '%' ? to_del + 1 : to_del;
	size = ft_strlen(format) + input->length - to_del;
	i = ft_strlen(format) - to_del - p;
	if (!(dest = ft_strnew(size)))
		ft_exit();
	ft_strncpy(dest, format, p);
	if (input->conv != 'c' && input->ischarnull == 0)
		ft_strncpy(&dest[p], input->final, input->length);
	else
		pf_handle_copy(dest, input, p);
	ft_strncpy(&dest[p + input->length], &format[p + to_del], i);
	return (dest);
}
