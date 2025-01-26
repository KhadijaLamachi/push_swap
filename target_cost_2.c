/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_cost_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:47:49 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/24 18:44:14 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void find_minabove(t_list *lst_b, t_list **previous, int count)
{
	int	min_above;
    t_list *target;
    int i;

    i = 0;
    if (count == 0)
        return ;
    min_above = previous[0]->content;
    target = previous[0];
	while (i < count)
	{
		if (previous[i]->content < min_above)
		{
			min_above = previous[i]->content;
			target = previous[i];
		}
		i++;
	}
    lst_b->target = target;
}

static void    realmin(t_list *lst_b, t_list *lst_a)
{
    int min;
    t_list  *target;

    min = lst_a->content;
    target = lst_a;
    while (lst_a)
    {
        if (lst_a->content < min)
        {
            min = lst_a->content;
            target = lst_a;
        }
        lst_a = lst_a->next;
    }
    lst_b->target = target;
}

void	get_target_2(t_list **stack_b, t_list	**stack_a)
{
	int	i;
	t_list **previous;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_b = *stack_b;
	while (lst_b)
	{
        previous = malloc(ft_lstsize(*stack_a) * sizeof(t_list *));
        if (!previous)
            return ;
		lst_a = *stack_a;
        i = 0;
		while (lst_a)
		{
			if (lst_a->content > lst_b->content)
				previous[i++] = lst_a;
            lst_a = lst_a->next;
		}
		find_minabove(lst_b, previous, i);
        if (i == 0)
            realmin(lst_b, *stack_a);
		lst_b = lst_b->next;
        free(previous);
	}
}

// static void cost(t_list *stack, t_list *node, int size_stack)
// {
//     int pos;

//     pos = 0;
    
//     while (stack != node)
//     {
//         stack = stack->next;
//         pos++;
//     }
//     if (pos <= size_stack/2)
//         node->cost = pos;
//     else
//         node->cost = size_stack - pos;
// }

// void    costs(t_list *stack)
// {
//     int size_stack;
//     t_list  *lst;

//     lst = stack;
//     size_stack = ft_lstsize(stack);
//     while (lst)
//     {
//         cost(stack, lst, size_stack);
//         lst = lst->next;
//     }
// }