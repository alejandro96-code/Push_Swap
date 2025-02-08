NAME = push_swap


# Falta añadir el resto de archivos
SRC =	main.c \


                
OBJS = $(SRC:.c=.o)

UNAME_S := $(shell uname -s)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME)

%.o: %.c
	@$(CC) -I $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)	
	@printf "\e[43m\e[30mCompilando Archivos Propios\e[0m\n"
	@$(CC) $(OBJS) -o $(NAME)
	@printf "\e[42m\e[30mArchivos Propios Compilados\e[0m\n"

clean:
	@rm -f $(OBJS)
	@printf "\e[42m\e[30mEliminados los archivos generados propios .o\e[0m\n"


fclean: clean
	rm -f $(NAME)
	@printf "\e[42m\e[30mEliminados todos los archivos generados\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
