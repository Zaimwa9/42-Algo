/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:11:23 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/23 19:02:57 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	char	**p;
	t_tetro	*tetros;

	if ((tetros = (t_tetro*)malloc(sizeof(t_tetro))) == NULL)
	{
		ft_error(NULL);
		return (0);
	}
	if (argc != 2)
	{
		ft_error("usage");
		return (0);
	}
	if ((p = ft_parse_file(argv[1])) == NULL)
	{
		ft_error(NULL);
		return (0);
	}
	tetros = ft_initiate(p);
	ft_solve(tetros);
	return (0);
}
