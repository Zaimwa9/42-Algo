/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:42:02 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/26 17:42:04 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		pf_parse(const char *format, va_list ap, t_caracs *input)
{
	pf_struct_init(input);
	if (format[0] == '\0')
		return (-1);
	if (pf_find_conv(format, input) == -1)
		return (-1);
	pf_find_opts(format, input);
	pf_get_prec(format, input, ap);
	pf_get_width(format, input, ap);
	if (input->conv == 'x' || input->conv == 'X' || input->conv == 'p')
		input->base = 16;
	if (input->conv == 'o' || input->conv == 'O')
		input->base = 8;
	pf_get_type(input);
	input->base = ft_strcmp(input->type, "wchar_t *") == 0 ? 2 : input->base;
	input->base = ft_strcmp(input->type, "wchar_t") == 0 ? 2 : input->base;
	pf_get_output(input, ap);
	if ((input->conv == 'c' || input->conv == 'C') && input->raw_output[0] == 0)
		input->ischarnull = 1;
	pf_calculs(input);
	return (1);
}

void	pf_check_null(t_caracs *input, va_list ap)
{
	char	*str;

	if (!(str = va_arg(ap, char *)))
		input->raw_output = ft_strdup("(null)");
	else
		input->raw_output = ft_strdup(str);
}

int		pf_issize(const char *format, int flag)
{
	int		j;

	if (flag == 0)
	{
		j = 6;
		while (--j >= 0)
		{
			if (ft_strncmp(format, g_sizes[0][j], ft_strlen(g_sizes[0][j]))
				== 0)
				return (j);
		}
		return (-1);
	}
	else if (flag == 1)
	{
		j = 14;
		while (--j >= 0)
		{
			if (ft_strncmp(format, g_conv[0][j], 1) == 0)
				return (j);
		}
		return (-1);
	}
	return (-1);
}
