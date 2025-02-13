NAME=push_swap

BONUS_NAME=checker

CC=cc

CFLAGS=-Wall -Wextra -Werror

SRC=linked_list.c push.c revrotate.c rotate.c swap.c libft_utils.c sort_stack.c push_swap.c input_handler.c input_handler2.c push_to_stack_b.c push_to_stack_a.c utils.c ft_split.c target.c cost.c 

SRC_BONUS=push_swap_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c linked_list_bonus.c utils_bonus.c libft_utils_bonus.c input_handler_bonus.c input_handler2_bonus.c ft_split_bonus.c

OBJ=$(SRC:.c=.o)

OBJ_BONUS=$(SRC_BONUS:.c=.o)

.PHONY: all clean fclean re bonus

all:$(NAME)

bonus:$(BONUS_NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME):$(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
