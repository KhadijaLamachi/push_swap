/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:12:50 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/02 11:46:38 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, const char *operation)
{
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	ft_lstadd_back(stack, tmp);
	*stack = (*stack)->next;
	tmp->next = NULL;
	if (operation && (ft_strcmp(operation, "ra") == 0))
		write(1, "ra\n", 3);
	else if (operation && (ft_strcmp(operation, "rb") == 0))
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, "rr");
	rotate(stack_b, "rr");
	write(1, "rr\n", 3);
}
