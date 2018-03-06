/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:22:16 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/28 14:12:46 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*ft_position(char **s, int flag)
{
	int		*posx;
	int		*posy;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	posx = (int*)malloc(sizeof(int) * 4);
	posy = (int*)malloc(sizeof(int) * 4);
	while (s[x] != NULL)
	{
		y = 0;
		while (y < 4 && i < 4)
		{
			if (s[x][y] == '#')
			{
				posx[i] = x;
				posy[i++] = y;
			}
			y++;
		}
		x++;
	}
	return ((flag == 0) ? posx : posy);
}

void		ft_offset(int *t, t_tetro *lst, int flag)
{
	int		i;
	int		min;

	i = 0;
	min = 4;
	while (i < 4)
	{
		if (t[i] < min)
			min = t[i];
		i++;
	}
	while (i >= 0)
	{
		if (flag == 0)
			lst->x[i] = t[i] - min;
		else
			lst->y[i] = t[i] - min;
		i--;
	}
}

t_tetro		*ft_initiate(char **p)
{
	int		i;
	char	**s;
	t_tetro	*tetro;
	t_tetro	*cursor;

	i = 0;
	if ((cursor = (t_tetro*)malloc(sizeof(t_tetro))) == NULL)
		return (NULL);
	tetro = cursor;
	while (p[i])
	{
		if ((s = ft_strsplit(p[i], '\n')) == NULL)
			return (NULL);
		cursor->letter = (char)malloc(1);
		cursor->letter = ('A' + i);
		ft_offset(ft_position(s, 0), cursor, 0);
		ft_offset(ft_position(s, 1), cursor, 1);
		free(s);
		if ((cursor->next = (t_tetro*)malloc(sizeof(t_tetro))) == NULL)
			return (NULL);
		cursor = cursor->next;
		cursor->next = NULL;
		i++;
	}
	return (tetro);
}
