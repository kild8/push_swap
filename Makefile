NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = 	check_arg.c \
		check_double.c \
		check_utils.c \
		fill.c \
		free_and_exit.c \
		main.c \
		move.c \
		push_back.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sort_three.c \
		sort_utils.c \
		sort.c \
		split_and_fill.c \
		swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re