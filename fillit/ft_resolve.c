/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:58:04 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/28 14:30:49 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_size(t_tetro *tetros)
{
	int	i;

	i = 0;
	while (tetros->next)
	{
		i++;
		tetros = tetros->next;
	}
	return (i);
}

static char		**ft_generate_grid(char **oldgrid, int size)
{
	char	**grid;
	int		i;

	i = 0;
	if ((grid = (char**)malloc(sizeof(char*) * size + 1)) == NULL)
		return (NULL);
	while (i < size)
		grid[i++] = ft_memset(ft_strnew(size), '.', size);
	grid[i] = NULL;
	if (oldgrid)
		i = 0;
	while (i < size - 1)
	{
		ft_strncpy(grid[i], oldgrid[i], size - 1);
		i++;
	}
	free(oldgrid);
	oldgrid = NULL;
	return (grid);
}

static int		ft_placing(t_tetro *tetros, char **grid, int x[2], int size)
{
	int	p;
	int i;
	int j;

	i = x[0];
	j = x[1];
	p = 0;
	while (p < 4)
	{
		if ((tetros->x[p] + i) > size - 1
			|| (tetros->y[p] + j) > size - 1
			|| grid[i + tetros->x[p]][j + tetros->y[p]] != '.')
			return (0);
		p++;
	}
	p = 0;
	while (p < 4)
	{
		grid[i + tetros->x[p]][j + tetros->y[p]] = tetros->letter;
		p++;
	}
	return (1);
}

int				ft_algo(t_tetro *tetros, char **grid, int size, int max)
{
	int x[2];

	x[0] = 0;
	if (max == 0)
		return (1);
	while (x[0] < size)
	{
		x[1] = 0;
		while (x[0] < size && x[1] < size)
		{
			if (ft_placing(tetros, grid, x, size))
			{
				max--;
				if ((tetros->next) && !ft_algo(tetros->next, grid, size, max))
					ft_clean_table(tetros, grid, size);
				else
					return (1);
				max++;
			}
			x[1]++;
		}
		x[0]++;
	}
	return (0);
}

void			ft_solve(t_tetro *tetros)
{
	char	**grid;
	size_t	size;
	int		flag;
	size_t	nbt;

	flag = 0;
	nbt = ft_size(tetros);
	size = ft_csqrt(nbt * 4);
	grid = ft_generate_grid(NULL, size);
	while (flag == 0)
	{
		if (ft_algo(tetros, grid, size, nbt) == 1)
		{
			ft_print_table(grid);
			flag = 1;
		}
		else
		{
			size++;
			grid = ft_generate_grid(grid, size);
		}
	}
}
