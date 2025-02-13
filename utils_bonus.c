/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:24:21 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/08 21:15:48 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_list **src_stack, t_list **dst_stack)
{
	t_list	*tmp;

	if (!*src_stack)
		return ;
	tmp = *src_stack;
	*src_stack = (*src_stack)->next;
	tmp->next = *dst_stack;
	*dst_stack = tmp;
}

void	revrotate(t_list **stack)
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
			return ;
		}
		lst = lst->next;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	ft_lstadd_back(stack, tmp);
	*stack = (*stack)->next;
	tmp->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
