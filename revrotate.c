/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:12:33 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/23 22:06:58 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*lst;
	
	lst = *stack_a;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	while (lst->next)
	{
		if (lst->next->next == NULL)
		{
			ft_lstadd_front(stack_a, lst->next);
			lst->next = NULL;
			ft_printf("rra\n");
			return ;
		}
		lst = lst->next;
	}
}


void	rrb(t_list **stack_b)
{
	t_list	*lst;
	
	lst = *stack_b;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	while (lst->next)
	{
		if (lst->next->next == NULL)
		{
			ft_lstadd_front(stack_b, lst->next);
			lst->next = NULL;
			ft_printf("rrb\n");
			return ;
		}
		lst = lst->next;
	}
}

static void	use_rra(t_list **stack_a)
{
	t_list	*lst;
	
	lst = *stack_a;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	while (lst->next)
	{
		if (lst->next->next == NULL)
		{
			ft_lstadd_front(stack_a, lst->next);
			lst->next = NULL;
			return ;
		}
		lst = lst->next;
	}
}


static void	use_rrb(t_list **stack_b)
{
	t_list	*lst;
	
	lst = *stack_b;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	while (lst->next)
	{
		if (lst->next->next == NULL)
		{
			ft_lstadd_front(stack_b, lst->next);
			lst->next = NULL;
			return ;
		}
		lst = lst->next;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		use_rra(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		use_rrb(stack_b);
	ft_printf("rrr\n");
}