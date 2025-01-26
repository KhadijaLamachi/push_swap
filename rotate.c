/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:53 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/23 22:06:27 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	ft_lstadd_back(stack_a, tmp);
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
    ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	ft_lstadd_back(stack_b, tmp);
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
    ft_printf("rb\n");
}

static void	use_ra(t_list **stack_a)
{
	t_list	*tmp;
	
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	ft_lstadd_back(stack_a, tmp);
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
}

static void	use_rb(t_list **stack_b)
{
	t_list	*tmp;
	
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	ft_lstadd_back(stack_b, tmp);
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		use_ra(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		use_rb(stack_b);
	ft_printf("rr\n");
}