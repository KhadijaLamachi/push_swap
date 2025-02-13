/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:20:33 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/01 20:35:17 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost(t_list *stack)
{
	int		pos;
	int		size_stack;
	t_list	*lst;

	pos = 0;
	lst = stack;
	size_stack = ft_lstsize(stack);
	while (lst)
	{
		is_bellowmed(stack, lst);
		if (lst->bellowmed == 0)
			lst->cost = pos;
		else
			lst->cost = size_stack - pos;
		lst = lst->next;
		pos++;
	}
}

void	sum_costs(t_list *stack_b)
{
	while (stack_b)
	{
		if (stack_b->bellowmed == 0 && stack_b->target->bellowmed == 0)
		{
			if (stack_b->cost < stack_b->target->cost)
				stack_b->cost = stack_b->target->cost;
		}
		else if (stack_b->bellowmed == 1 && stack_b->target->bellowmed == 1)
		{
			if (stack_b->cost < stack_b->target->cost)
				stack_b->cost = stack_b->target->cost;
		}
		else
			stack_b->cost += stack_b->target->cost;
		stack_b = stack_b->next;
	}
}
