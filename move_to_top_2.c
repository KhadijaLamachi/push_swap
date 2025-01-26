/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:49:17 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/24 15:19:24 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	both_inferior(t_list **stack_b, t_list **stack_a, t_list *min_node)
{
	while (min_node->cost > 0 && min_node->target->cost > 0)
	{
		rr(stack_a, stack_b);
		min_node->cost--;
		min_node->target->cost--;
	}
	if (min_node->cost > 0 && min_node->target->cost == 0)
	{
		while (min_node->cost > 0)
		{
			rb(stack_b);
			min_node->cost--;
		}
	}
	else if (min_node->cost == 0 && min_node->target->cost > 0)
	{
		while (min_node->target->cost > 0)
		{
			ra(stack_a);
			min_node->target->cost--;
		}
	}
}

static void	both_superior(t_list **stack_b, t_list **stack_a, t_list *min_node)
{
	while (min_node->cost > 0 && min_node->target->cost > 0)
	{
		rrr(stack_a, stack_b);
		min_node->cost--;
		min_node->target->cost--;
	}
	if (min_node->cost > 0 && min_node->target->cost == 0)
	{
		while (min_node->cost > 0)
		{
			rrb(stack_b);
			min_node->cost--;
		}
	}
	else if (min_node->cost == 0 && min_node->target->cost > 0)
	{
		while (min_node->target->cost > 0)
		{
			rra(stack_a);
			min_node->target->cost--;
		}
	}
}

static void	a_superior_b_inferior(t_list **stack_b, t_list **stack_a, t_list *min_node)
{
	while (min_node->cost > 0)
	{
		rrb(stack_b);
		min_node->cost--;
	}
	while (min_node->target->cost > 0)
	{
		ra(stack_a);
		min_node->target->cost--;
	}
}

static void	a_inferior_b_superior(t_list **stack_b, t_list **stack_a, t_list *min_node)
{
	while (min_node->cost > 0)
	{
		rb(stack_b);
		min_node->cost--;
	}
	while (min_node->target->cost > 0)
	{
		rra(stack_a);
		min_node->target->cost--;
	}
}

void    move_to_top_2(t_list **stack_b, t_list **stack_a, t_list *min_node)
{
    int size_stack_a;
    int size_stack_b;

    size_stack_a = ft_lstsize(*stack_a);
    size_stack_b = ft_lstsize(*stack_b);
	if (min_node->cost == 0 && min_node->target->cost == 0)
		return ;
    if ((min_node->cost <= size_stack_a / 2) && (min_node->target->cost <= size_stack_b / 2) )
        both_inferior(stack_b, stack_a, min_node);
    else if ((min_node->cost > size_stack_a / 2) && (min_node->target->cost > size_stack_b / 2))
    	both_superior(stack_b, stack_a, min_node);
    else if ((min_node->cost > size_stack_a / 2) && (min_node->target->cost < size_stack_b / 2))
        a_superior_b_inferior(stack_b, stack_a, min_node);
    else if ((min_node->cost < size_stack_a / 2) && (min_node->target->cost > size_stack_b / 2))
        a_inferior_b_superior(stack_b, stack_a, min_node);
}
