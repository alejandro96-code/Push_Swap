NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       operations.c \
       operations_combined.c \
       sorting.c \
       utils_stack.c \
       utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re