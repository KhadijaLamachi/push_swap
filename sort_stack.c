/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:58:08 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/02 17:42:56 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, "sa");
}

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a)
		return ;
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if ((a < b) && (b > c) && (a < c))
	{
		swap(stack_a, "sa");
		rotate(stack_a, "ra");
	}
	else if ((a > b) && (b < c) && (a < c))
		swap(stack_a, "sa");
	else if ((a < b) && (b > c) && (a > c))
		revrotate(stack_a, "rra");
	else if ((a > b) && (b < c) && (a > c))
		rotate(stack_a, "ra");
	else if ((a > b) && (b > c))
	{
		swap(stack_a, "sa");
		revrotate(stack_a, "rra");
	}
}

void	sort_small_stack(t_list **stack_a, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		size;
	t_list	*min_node;

	size = ft_lstsize(*stack_a);
	if (size <= 3)
		sort_small_stack(stack_a, size);
	else
	{
		push_to_b(stack_a, stack_b);
		sort_three(stack_a);
		push_to_a(stack_a, stack_b);
	}
	min_node = find_min(*stack_a);
	is_bellowmed(*stack_a, min_node);
	if (is_sorted(*stack_a) == 0)
	{
		while (*stack_a != min_node)
		{
			if (min_node->bellowmed == 0)
				rotate(stack_a, "ra");
			else
				revrotate(stack_a, "rra");
		}
	}
}
