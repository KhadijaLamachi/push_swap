/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:22:43 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/24 16:05:31 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void find_maxbellow(t_list *lst_a, t_list **previous, int count)
{
	int	max_bellow;
    t_list *target;
    int i;

    i = 0;
    if (count == 0)
        return ;
    max_bellow = previous[0]->content;
    target = previous[0];
	while (i < count)
	{
		if (previous[i]->content > max_bellow)
		{
			max_bellow = previous[i]->content;
			target = previous[i];
		}
		i++;
	}
    lst_a->target = target;
}

static void    realmax(t_list *lst_a, t_list *lst_b)
{
    int max;
    t_list  *target;

    max = lst_b->content;
    target = lst_b;
    while (lst_b)
    {
        if (lst_b->content > max)
        {
            max = lst_b->content;
            target = lst_b;
        }
        lst_b = lst_b->next;
    }
    lst_a->target = target;
}

void	get_target(t_list **stack_a, t_list	**stack_b)
{
	int	i;
	t_list **previous;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = *stack_a;
	while (lst_a)
	{
        previous = malloc(ft_lstsize(*stack_b) * sizeof(t_list *));
        if (!previous)
            return ;
		lst_b = *stack_b;
        i = 0;
		while (lst_b)
		{
			if (lst_b->content < lst_a->content)
				previous[i++] = lst_b;
            lst_b = lst_b->next;
		}
		find_maxbellow(lst_a, previous, i);
        if (i == 0)
            realmax(lst_a, *stack_b);
		lst_a = lst_a->next;
        free(previous);
	}
}

static void cost(t_list *stack, t_list *node, int size_stack)
{
    int pos;

    pos = 0;
    
    while (stack != node)
    {
        stack = stack->next;
        pos++;
    }
    if (pos <= size_stack/2)
        node->cost = pos;
    else
        node->cost = size_stack - pos;
}

void    costs(t_list *stack)
{
    int size_stack;
    t_list  *lst;

    lst = stack;
    size_stack = ft_lstsize(stack);
    while (lst)
    {
        cost(stack, lst, size_stack);
        lst = lst->next;
    }
}
