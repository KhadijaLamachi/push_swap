/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:07:28 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/02 11:15:00 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *operation)
{
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (operation)
	{
		if (ft_strcmp(operation, "sa") == 0)
			write(1, "sa\n", 3);
		else if (ft_strcmp(operation, "sb") == 0)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, "ss");
	swap(stack_b, "ss");
	write(1, "ss\n", 3);
}
