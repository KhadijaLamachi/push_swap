/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:04:07 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/08 21:00:16 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_list *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	rest_instructions(t_list **stack_a, t_list **stack_b, char **line)
{
	if (ft_strcmp(*line, "rra\n") == 0)
		revrotate(stack_a);
	else if (ft_strcmp(*line, "rrb\n") == 0)
		revrotate(stack_b);
	else if (ft_strcmp(*line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(*line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
	{
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		free(*line);
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	execute_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "sa\n") == 0)
			swap(stack_a);
		else if (ft_strcmp(line, "sb\n") == 0)
			swap(stack_b);
		else if (ft_strcmp(line, "ss\n") == 0)
			ss(stack_a, stack_b);
		else if (ft_strcmp(line, "pa\n") == 0)
			push(stack_b, stack_a);
		else if (ft_strcmp(line, "pb\n") == 0)
			push(stack_a, stack_b);
		else if (ft_strcmp(line, "ra\n") == 0)
			rotate(stack_a);
		else if (ft_strcmp(line, "rb\n") == 0)
			rotate(stack_b);
		else
			rest_instructions(stack_a, stack_a, &line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	handle_input(argv, &stack_a);
	execute_instructions(&stack_a, &stack_b);
	if ((is_sorted(stack_a) == 1) && (stack_b == NULL))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
}
