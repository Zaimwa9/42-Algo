/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:16:39 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/23 19:07:29 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFFER 4096

typedef struct	s_tetro
{
	char			letter;
	int				x[4];
	int				y[4];
	struct s_tetro	*next;
}				t_tetro;

int				main(int argc, char **argv);
void			ft_error(const char *err);
char			**ft_parse_file(const char *file);
void			ft_solve(t_tetro *tetros);
void			ft_print_table(char **tab);
int				*ft_position(char **s, int flag);
void			ft_offset(int *t, t_tetro *lst, int flag);
void			ft_clean_table(t_tetro *tetros, char **grid, int size);
t_tetro			*ft_initiate(char **p);
#endif
