/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:02:19 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/15 16:08:14 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
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
		sa(stack_a);
		ra(stack_a);
	}
	else if ((a > b) && (b < c) && (a < c))
		sa(stack_a);
	else if ((a < b) && (b > c)  && (a > c))
		rra(stack_a);
	else if ((a > b) && (b < c) && (a > c))
		ra(stack_a);
	else if ((a > b) && (b > c))
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;
	int min;
	if (!stack_a || !(*stack_a) || !stack_b)
		return ;
	lst = *stack_a;
	min = (*stack_a)->content;
	while (lst)
	{
		if (min > lst->content)
			min = lst->content;
		lst = lst->next;
	}
	while (min != (*stack_a)->content)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	push_min(t_list **stack_a)
{
	t_list	*lst;
	int		min;

	lst = *stack_a;
	min = lst->content;
	while (lst)
	{
		if (min > lst->content)
			min = lst->content;
		lst = lst->next;
	}
	while (min != (*stack_a)->content)
		ra(stack_a);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !(*stack_a) || !stack_b)
		return ;

	push_min(stack_a);
	pb(stack_a, stack_b);
	push_min(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b, int size)
{
	
	if (size == 2)
	{
		sort_two(stack_a);
	}
	else if (size == 3)
	{
		sort_three(stack_a);
	}
	else if (size == 4)
	{
		sort_four(stack_a, stack_b);
	}
	else if (size == 5)
	{
		sort_five(stack_a, stack_b);
	}
}
