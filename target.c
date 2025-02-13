/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:35:45 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/01 11:15:28 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*target;
	int		max;

	lst_b = *stack_b;
	while (lst_b)
	{
		lst_a = *stack_a;
		max = INT_MAX;
		target = NULL;
		while (lst_a)
		{
			if (lst_b->content < lst_a->content && lst_a->content < max)
			{
				max = lst_a->content;
				target = lst_a;
			}
			lst_a = lst_a->next;
		}
		if (target == NULL)
			target = find_min(*stack_a);
		lst_b->target = target;
		lst_b = lst_b->next;
	}
}
