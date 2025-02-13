/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:25:17 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/02 10:51:27 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*cheapest(t_list *stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = stack_b;
	while (stack_b)
	{
		if (stack_b->cost < cheapest_node->cost)
			cheapest_node = stack_b;
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}

void	move_to_top(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	is_bellowmed(*stack_b, cheapest_node);
	if (cheapest_node->bellowmed == 0 && cheapest_node->target->bellowmed == 0)
		while (cheapest_node != *stack_b && cheapest_node->target != *stack_a)
			rr(stack_a, stack_b);
	if (cheapest_node->bellowmed == 1 && cheapest_node->target->bellowmed == 1)
		while (cheapest_node != *stack_b && cheapest_node->target != *stack_a)
			rrr(stack_a, stack_b);
	while ((*stack_b) != cheapest_node)
	{
		if (cheapest_node->bellowmed == 0)
			rotate(stack_b, "rb");
		else
			revrotate(stack_b, "rrb");
	}
	while ((*stack_a) != cheapest_node->target)
	{
		if (cheapest_node->target->bellowmed == 0)
			rotate(stack_a, "ra");
		else
			revrotate(stack_a, "rra");
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	while (*stack_b)
	{
		target(stack_a, stack_b);
		cost(*stack_a);
		cost(*stack_b);
		sum_costs(*stack_b);
		cheapest_node = cheapest(*stack_b);
		move_to_top(stack_a, stack_b, cheapest_node);
		push(stack_b, stack_a, "pa");
	}
}
