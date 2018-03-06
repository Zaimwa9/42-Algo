/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:05:57 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/29 19:05:58 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_init_globals(void)
{
	g_sizes[0][0] = "h";
	g_sizes[0][1] = "hh";
	g_sizes[0][2] = "l";
	g_sizes[0][3] = "ll";
	g_sizes[0][4] = "j";
	g_sizes[0][5] = "z";
	g_conv[0][0] = "s";
	g_conv[0][1] = "S";
	g_conv[0][2] = "p";
	g_conv[0][3] = "d";
	g_conv[0][4] = "D";
	g_conv[0][5] = "i";
	g_conv[0][6] = "o";
	g_conv[0][7] = "O";
	g_conv[0][8] = "u";
	g_conv[0][9] = "U";
	g_conv[0][10] = "x";
	g_conv[0][11] = "X";
	g_conv[0][12] = "c";
	g_conv[0][13] = "C";
	pf_init_globals2();
}

void	pf_init_globals2(void)
{
	g_conv[1][0] = "char *";
	g_conv[1][1] = "wchar_t *";
	g_conv[1][2] = "void *";
	g_conv[1][3] = "int";
	g_conv[1][4] = "long";
	g_conv[1][5] = "int";
	g_conv[1][6] = "unsigned int";
	g_conv[1][7] = "unsigned long";
	g_conv[1][8] = "unsigned int";
	g_conv[1][9] = "unsigned long";
	g_conv[1][10] = "unsigned int";
	g_conv[1][11] = "unsigned int";
	g_conv[1][12] = "char";
	g_conv[1][13] = "wchar_t";
}

void	pf_struct_init(t_caracs *input)
{
	input->length = -1;
	input->hasopt = 0;
	input->space = 0;
	input->hash = 0;
	input->plus = 0;
	input->minus = 0;
	input->zero = 0;
	input->width = 0;
	input->prec = -1;
	input->size = "notdef";
	input->conv = 0;
	input->convidx = -1;
	input->type = NULL;
	input->base = 10;
	input->isdef = 1;
	input->isneg = 0;
	input->isrelou = 0;
	input->ischarnull = 0;
	input->hasdot = 0;
	input->canczero = 0;
	input->padchar = ' ';
	input->raw_output = NULL;
	input->final = NULL;
}
