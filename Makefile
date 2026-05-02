NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJDIR = obj

SRCS = main.c \
       operations.c \
       operations_combined.c \
       short_small.c \
       stack_utils.c \
       stack_values.c \
       check_utils.c \
       memory.c \
       split_utils.c \
       index_utils.c \
       position_utils.c \
       cost_utils.c \
       rotation_utils.c \
       push_utils.c \
       big_sort.c \

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.c push_swap.h
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re