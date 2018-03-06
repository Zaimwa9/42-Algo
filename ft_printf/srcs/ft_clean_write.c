/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:41:54 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/17 16:41:55 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	ft_write_null(const char *s, int isnull)
{
	char		c;
	int			size;
	const char	*tmp;
	int			tot;

	tmp = s;
	c = 0;
	while (isnull > 0)
	{
		size = ft_strlen(tmp);
		write(1, s, size);
		write(1, &c, 1);
		tot = size + 1;
		isnull--;
		tmp = &s[size + 1];
		write(1, tmp, ft_strlen(tmp));
		tot = tot + ft_strlen(tmp);
	}
	return (tot);
}

int			ft_clean_write(const char *s, int isnull)
{
	int		size;

	size = ft_strlen(s);
	if (isnull == 0)
		write(1, s, size);
	if (isnull > 0)
		return (ft_write_null(s, isnull));
	return (size);
}

int			ft_clean_write_null(const char *s, int isnull, int max)
{
	char		c;
	int			size;
	const char	*tmp;
	int			tot;

	tmp = s;
	c = 0;
	tot = 0;
	if (isnull > 0)
	{
		size = ft_strlen(tmp);
		write(1, s, size);
		write(1, &c, 1);
		max = max - size - 1;
		tot = size + 1;
		isnull--;
		tmp = &s[size + 1];
		write(1, tmp, max);
		tot = tot + max;
	}
	return (tot);
}

int			ft_write_ichar(const char *s, int n)
{
	write(1, s, n);
	return (n);
}

int			ft_write_nullchar(const char *s)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	i++;
	write(1, &c, 1);
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	return (i);
}
