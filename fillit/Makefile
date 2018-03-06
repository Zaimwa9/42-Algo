SRC_PATH = ./
OBJ_PATH = ./
INC_PATH = ./

NAME = fillit
CC = gcc
CFLAGS = -Werror -Wextra -Wall

complete = @echo "\033[92mComplete\033[0m"
cleaning = @echo "\033[36mCleaning complete\033[0m"

SRC_NAME  = main.c \
			ft_error.c \
			ft_parse_file.c \
			ft_resolve.c \
			ft_settetro.c \
			ft_print_table.c

OBJ_NAME = $(SRC_NAME.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33mLaunching Makefile for Libft..\033[0m"
	@make -C ./libft
	@echo "**************************************"
	@echo "\033[33mBuilding Fillit..\033[0m"
	@echo "Compiling sources into a program.."
	@$(CC) $(CFLAGS) -L./libft/ -lft $(SRC) $(INC) -o $(NAME)
	$(complete)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "Compilating files into binaries.."
	$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<

clean:
	@echo "**************************************"
	@echo "\033[33mCleaning process for Libft engaged..\033[0m"
	@make clean -C ./libft
	$(cleaning)
	@echo "**************************************"
	@echo "\033[33mCleaning process for Fillit engaged..\033[0m"
	@echo "Removing Fillit binaries.."
	@rm -f $(OBJ)
	$(cleaning)

fclean: clean
	@echo "\033[33mCleaning library and program..\033[0m"
	@echo "Removing program named Fillit.."
	@rm -f $(NAME)
	@make fclean -C ./libft
	$(cleaning)
	@echo "**************************************"

re: fclean all
