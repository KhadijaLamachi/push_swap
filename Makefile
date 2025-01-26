EXEC = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = few_args.c ft_atoi.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c linkedlist.c main.c push.c revrotate.c rotate.c swap.c target_cost.c move_to_top.c stacka_to_stackb.c move_to_top_2.c target_cost_2.c

OBJ = $(SRC:.c=.o)

PRINTF_DIR = ft_printf

PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

.PHONY: all clean fclean re

all: $(EXEC)

$(EXEC): $(OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(PRINTF_LIB) -o $@ $^

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

PRINTF_LIB:
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(EXEC)
	make fclean -C $(PRINTF_DIR)

re: fclean all
