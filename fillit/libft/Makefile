# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzaim <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:26:15 by wzaim             #+#    #+#              #
#    Updated: 2017/11/24 11:39:24 by fmadura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -c
CFLAGS = -Wall -Wextra -Werror

complete = @echo "\033[92mComplete\033[0m"

SRC_DIR = ./
SRC_NAMES = ft_csqrt.c \
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
			ft_memset.c \
			ft_strcat.c \
			ft_strdup.c \
			ft_strndup.c\
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

SRC = $(addprefix $(SRC_DIR), $(SRC_NAMES))

OBJ_DIR = ./
OBJ_NAMES = $(SRC_NAMES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAMES))

INC_DIR = ./
INC = $(addprefix -I, $(INC_DIR))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling the libft.."
	@ar rc $(NAME) $(OBJ)
	@echo "Indexing the libft.."
	@ranlib $(NAME)
	$(complete)
	
%.o: %.c
	@gcc -o $@ -c $< $(INC) $(CFLAGS)

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaning static library libft.."

clean:
	@rm -f $(OBJ)
	@echo "Cleaning object files from libft.."

re: fclean all
