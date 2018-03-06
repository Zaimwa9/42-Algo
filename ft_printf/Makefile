# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzaim <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:26:15 by wzaim             #+#    #+#              #
#    Updated: 2018/02/01 10:49:58 by wzaim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRC_NAMES = ft_printf.c \
			pf_printf_rec.c \
			pf_string_ops.c \
			pf_init.c \
			pf_get_output.c \
			pf_extractors.c \
			pf_type_func2.c \
			pf_xo_testers.c \
			pf_handle_xo.c \
			pf_handle_di.c \
			pf_handle_cnull.c \
			pf_rework_struct.c \
			pf_widechar.c \
			pf_type_funcs.c \
			pf_read_args.c \
			pf_calculations.c \
			ft_exit.c \
			get_next_line.c \
			ft_strcapitalize.c \
			ft_clean_write.c \
			ft_strichrn.c \
			ft_itoa_ull.c \
			ft_itoa_ul.c \
			ft_atoi_l.c \
			ft_atoi_ll.c \
			ft_get_nb_digits.c \
			ft_itoa_base.c \
			ft_itoa_base_ull.c \
			ft_toupper.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isascii.c \
			ft_isalnum.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_strcmp.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strclr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_strcat.c \
			ft_strdup.c \
			ft_strichr.c \
			ft_strncat.c \
			ft_strncpy.c \
			ft_strncmp.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_bzero.c \
			ft_strlcat.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memset.c \
			ft_memccpy.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_atoi.c \
			ft_strnew.c \
			ft_strsub.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strdel.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strsplit.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_itoa.c \
			ft_memcpy.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_is_prime.c \
			ft_sqrt.c \
			ft_power.c \
			ft_is_include.c \
			ft_strcpy.c

SRC_DIR = ./srcs/
SRC = $(addprefix $(SRC_DIR), $(SRC_NAMES))

OBJ_DIR = ./srcs/
OBJ_NAMES = $(SRC_NAMES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAMES))

INC_DIR = ./includes/
INC = $(addprefix -I, $(INC_DIR))

all: $(NAME)

test: $(OBJ)
	@echo "Generating with main"
	@gcc -o ./objs/main.o -c main.c
	@gcc $(INC) $(OBJ) ./objs/main.o -o printfbin

$(NAME): $(OBJ)
	@echo "Preparing libftprintf !"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libftprintf ready !"

./objs/%.o: ./srcs/%.c
	@$(CC) -Ofast -o $@ -c $< $(INC) $(CFLAGS)

fclean: clean
	@rm -f $(NAME)
	@echo "libft COMPLETELY cleaned boss !"

clean:
	@rm -f $(OBJ)

re: fclean all
	@echo "Encore du travail ? Treees bien"
