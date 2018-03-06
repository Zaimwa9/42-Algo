/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:02:02 by fmadura           #+#    #+#             */
/*   Updated: 2017/11/23 19:09:58 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_table(char **grid)
{
	int i;

	i = 0;
	while (grid[i] != NULL)
	{
		ft_putstr(grid[i++]);
		ft_putchar('\n');
	}
}

void	ft_clean_table(t_tetro *tetros, char **grid, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size && i < size)
		{
			if (grid[i][j] == tetros->letter)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
}
