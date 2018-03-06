/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:07:55 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/31 14:08:10 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_my_alloc(t_caracs **input)
{
	if (!(*input = (t_caracs *)malloc(sizeof(t_caracs))))
		ft_exit();
}

int		free_all(t_caracs *input, int flag)
{
	if (flag == 1)
	{
		free(input->raw_output);
		free(input->final);
		free(input);
	}
	if (flag == 0)
		free(input);
	return (1);
}

/*
** v[0] => isnullchar counter; v[1] => wip indicator; v[2] => printed chars
** v[3] => i
*/

int		ft_printf_rec(const char *fmt, int final, va_list ap)
{
	int			i[2];
	t_caracs	*input;

	i[0] = 0;
	i[1] = 0;
	if ((i[0] = ft_strichrn(fmt, '%', i[0])) < 0)
		return (ft_write_ichar(fmt, ft_strlen(fmt)));
	while ((i[0] = ft_strichrn(fmt, '%', i[0])) >= 0)
	{
		final += ft_write_ichar(&fmt[i[1]], i[0] - i[1]);
		if (!(input = (t_caracs *)malloc(sizeof(t_caracs))))
			ft_exit();
		if (pf_parse(&fmt[i[0] + 1], ap, input) == -1)
			return (free_all(input, 0));
		else if (input->ischarnull == 0)
			final += ft_write_ichar(input->final, ft_strlen(input->final));
		else if (input->ischarnull == 1)
			final += ft_write_nullchar(input->final);
		i[1] = ++i[0];
		while (fmt[i[0]] != input->conv)
			i[1] = i[0]++;
		i[1] = ++i[0];
		free_all(input, 1);
	}
	return (final += ft_write_ichar(&fmt[i[1]], ft_strlen(&fmt[i[1]])));
}
