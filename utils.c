/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:40:04 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/02 17:45:24 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *stack)
{
	t_list	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->content < min_node->content)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

void	is_bellowmed(t_list *stack, t_list *node)
{
	int	middle;
	int	pos;

	middle = ft_lstsize(stack) / 2;
	pos = 0;
	while (stack)
	{
		if (stack == node)
		{
			if (pos <= middle)
				node->bellowmed = 0;
			if (pos > middle)
				node->bellowmed = 1;
			return ;
		}
		stack = stack->next;
		pos++;
	}
}

int	is_sorted(t_list *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
