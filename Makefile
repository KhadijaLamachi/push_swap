EXEC = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = linked_list.c push.c revrotate.c rotate.c swap.c libft_utils.c sort_stack.c push_swap.c input_handler.c input_handler2.c push_to_stack_b.c push_to_stack_a.c utils.c ft_split.c target.c cost.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
