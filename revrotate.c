/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:20:45 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/02 11:12:56 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_list **stack, const char *operation)
{
	t_list	*lst;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	lst = *stack;
	while (lst->next)
	{
		if (lst->next->next == NULL)
		{
			ft_lstadd_front(stack, lst->next);
			lst->next = NULL;
			if (operation && (ft_strcmp(operation, "rra") == 0))
				write(1, "rra\n", 4);
			else if (operation && (ft_strcmp(operation, "rrb") == 0))
				write(1, "rrb\n", 4);
			return ;
		}
		lst = lst->next;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	revrotate(stack_a, 0);
	revrotate(stack_b, 0);
	write(1, "rrr\n", 4);
}
