/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:27:24 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/28 13:19:17 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_char(const char **tab)
{
	int		x;
	int		y;
	int		chars[3];

	x = 0;
	while ((tab[x]))
	{
		y = 0;
		chars[0] = 0;
		chars[1] = 0;
		chars[2] = 0;
		while ((tab[x][y]))
		{
			chars[0] += (tab[x][y] == '#');
			chars[1] += (tab[x][y] == '.');
			chars[2] += (tab[x][y] == '\n' && (chars[0] + chars[1]) % 4 == 0);
			if (tab[x][y] != '#' && tab[x][y] != '.' && tab[x][y] != '\n')
				return (0);
			y++;
		}
		if (chars[0] != 4 || chars[1] != 12 || chars[2] != 4)
			return (0);
		x++;
	}
	return (1);
}

static char	*ft_count_forms(const char *s)
{
	size_t	i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	str = ft_strdup(s);
	if (str == NULL || str[0] == '\n' || str[ft_strlen(str) - 1] != '\n')
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			if (i % (20 * (count + 1) + count) != 0 || str[i + 1] == '\0')
				return (NULL);
			str[i] = ' ';
			count++;
		}
		i++;
	}
	return (str);
}

static int	ft_check_valid_forms(char **s)
{
	int		i;
	int		hshtg;
	int		y;

	i = 0;
	hshtg = 0;
	while ((s[i]))
	{
		y = 0;
		while (y < 4)
		{
			if (s[i][y] == '#' && s[i][y + 1] == '#')
				hshtg++;
			if (y > 0 && s[i][y] == '#' && s[i][y - 1] == '#')
				hshtg++;
			if (i > 0 && s[i][y] == '#' && s[i - 1][y] == '#')
				hshtg++;
			if (i < 3 && s[i][y] == '#' && s[i + 1][y] == '#')
				hshtg++;
			y++;
		}
		i++;
	}
	return ((hshtg != 6 && hshtg != 8) ? 0 : 1);
}

static char	**ft_main_check(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	if ((tab = ft_strsplit(ft_count_forms(str), ' ')) == NULL)
		return (NULL);
	if (ft_check_char((const char **)tab) == 0)
		return (0);
	while ((tab[i]))
	{
		if (ft_check_valid_forms(ft_strsplit(tab[i++], '\n')) == 0)
			return (NULL);
	}
	return (tab);
}

char		**ft_parse_file(const char *file)
{
	int		fd;
	int		ret;
	char	buf[BUFFER];
	char	*str;
	char	**tab;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if ((ret = read(fd, &buf, BUFFER)) == -1 || ret == 0)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (ret + 1))) == NULL)
		return (NULL);
	if ((str = ft_strncpy(str, buf, ret)) == NULL)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	if ((tab = ft_main_check(str)) == NULL)
		return (NULL);
	else
		free(str);
	return (tab);
}
