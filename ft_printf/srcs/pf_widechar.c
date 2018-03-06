/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_widechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:51:34 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/19 13:52:49 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*wide_to_str(wint_t c)
{
	char	*str;

	if (!(str = ft_strnew(4)))
		ft_exit();
	if (c <= 0xFF)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) + 0xc0;
		str[1] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0xFFFF)
	{
		str[0] = (c >> 12) + 0xe0;
		str[1] = ((c >> 6) & 0x3f) + 0x80;
		str[2] = (c & 0x3f) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = (c >> 18) + 0xf0;
		str[1] = (c >> 12 & 0x3f) + 0x80;
		str[2] = (c >> 6 & 0x3f) + 0x80;
		str[3] = (c & 0x3f) + 0xc80;
	}
	return (str);
}

void	convert_wide_c(t_caracs *input, va_list ap)
{
	wint_t	c;

	c = va_arg(ap, wint_t);
	input->raw_output = wide_to_str(c);
}

void	convert_wide_s(t_caracs *input, va_list ap)
{
	wchar_t	*w_var;
	int		i;
	char	*dest;

	i = 0;
	w_var = va_arg(ap, wchar_t *);
	if (!w_var)
		input->raw_output = ft_strdup("(null)");
	else
	{
		while (w_var[i])
			i++;
		input->raw_output = ft_strnew(i * 4);
		i = 0;
		while (w_var[i])
		{
			dest = wide_to_str((wint_t)w_var[i++]);
			if (dest != NULL)
			{
				input->raw_output = ft_strcat(input->raw_output, dest);
				free(dest);
			}
		}
	}
}
