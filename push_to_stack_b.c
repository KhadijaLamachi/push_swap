/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:15:43 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/02 21:24:39 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rank(t_list **head)
{
	int		rank;
	t_list	*curr;
	t_list	*comp;

	curr = *head;
	while (curr)
	{
		rank = 0;
		comp = *head;
		while (comp)
		{
			if (curr->content > comp->content)
				rank++;
			comp = comp->next;
		}
		curr->rank = rank;
		curr = curr->next;
	}
}

void	push_by_rank(t_list **stack_a, t_list **stack_b)
{
	int	middle;

	get_rank(stack_a);
	middle = ft_lstsize(*stack_a) / 2;
	while ((*stack_a)->rank > middle)
		rotate(stack_a, "ra");
	push(stack_a, stack_b, "pb");
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		push_by_rank(stack_a, stack_b);
		size--;
	}
}
