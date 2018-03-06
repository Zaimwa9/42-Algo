/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:03:25 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/29 19:03:26 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		pf_get_output(t_caracs *input, va_list ap)
{
	if (input->conv == '%')
		input->raw_output = pf_get_ascii(37);
	else if (ft_strcmp(input->type, "wchar_t") == 0)
		convert_wide_c(input, ap);
	else if (ft_strcmp(input->type, "wchar_t *") == 0)
		convert_wide_s(input, ap);
	else if (ft_strcmp(input->type, "char *") == 0)
		pf_check_null(input, ap);
	else if (ft_strcmp(input->type, "unsigned int") == 0)
		input->raw_output =
		ft_itoa_base_ull((uintmax_t)va_arg(ap, unsigned int), input->base);
	else if (ft_strcmp(input->type, "int") == 0)
		input->raw_output = ft_itoa_base((int)va_arg(ap, int), input->base);
	else if (ft_strcmp(input->type, "short") == 0)
		input->raw_output = ft_itoa_base((short)va_arg(ap, int), input->base);
	else if (ft_strcmp(input->type, "uintmax_t") == 0)
		input->raw_output =
		ft_itoa_base_ull((uintmax_t)va_arg(ap, uintmax_t), input->base);
	else if (ft_strcmp(input->type, "intmax_t") == 0)
		input->raw_output =
		ft_itoa_base((intmax_t)va_arg(ap, intmax_t), input->base);
	else
		pf_get_output2(input, ap);
	return (1);
}

void	pf_get_output2(t_caracs *input, va_list ap)
{
	if (ft_strcmp(input->type, "intchar") == 0)
		input->raw_output =
		ft_itoa_base((signed char)va_arg(ap, int), input->base);
	else if (ft_strcmp(input->type, "char") == 0)
		input->raw_output = pf_get_ascii(va_arg(ap, int));
	else if (ft_strcmp(input->type, "unsigned short") == 0)
		input->raw_output =
		ft_itoa_base_ull((uintmax_t)va_arg(ap, int), input->base);
	else if (ft_strcmp(input->type, "ssize_t") == 0)
		input->raw_output =
		ft_itoa_base((uintmax_t)va_arg(ap, ssize_t), input->base);
	else if (ft_strcmp(input->type, "long") == 0)
		input->raw_output = ft_itoa(va_arg(ap, long));
	else if (ft_strcmp(input->type, "long long") == 0)
		input->raw_output =
		ft_itoa_base((uintmax_t)va_arg(ap, long long), input->base);
	else if (ft_strcmp(input->type, "void *") == 0)
		input->raw_output =
		ft_itoa_base_ull((uintmax_t)va_arg(ap, void *), input->base);
	else
		pf_get_output3(input, ap);
}

void	pf_get_output3(t_caracs *input, va_list ap)
{
	if (ft_strcmp(input->type, "size_t") == 0)
		input->raw_output =
		ft_itoa_base_ull((uintmax_t)va_arg(ap, size_t), input->base);
	else if (ft_strcmp(input->type, "unsigned int") == 0)
		input->raw_output =
		ft_itoa_base_ull((uintmax_t)va_arg(ap, unsigned int), input->base);
	else if (ft_strcmp(input->type, "unsigned long") == 0)
		input->raw_output =
		ft_itoa_base_ull((uintmax_t)va_arg(ap, unsigned long), input->base);
	else if (ft_strcmp(input->type, "unsigned long long") == 0)
		input->raw_output =
		ft_itoa_base_ull((uintmax_t)va_arg(ap, unsigned long long),
		input->base);
	else if (ft_strcmp(input->type, "unsigned char") == 0)
		input->raw_output =
		ft_itoa_base_ull((unsigned char)va_arg(ap, int), input->base);
}

char	*pf_get_ascii(int nb)
{
	char	*dest;

	if (!(dest = ft_strnew(1)))
		ft_exit();
	dest[0] = nb;
	return (dest);
}
