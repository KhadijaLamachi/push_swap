/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka_to_stackb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:49:15 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/24 16:10:20 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_node_minop(t_list **stack_a, t_list **stack_b)
{
    int min_op;
    t_list  *min_node;
    t_list  *lst;

    lst = *stack_a;
    min_op = lst->cost + lst->target->cost;
    min_node = lst;
    while (lst)
    {
        if (min_op > (lst->cost + lst->target->cost))
        {
            min_op = lst->cost + lst->target->cost;
            min_node = lst;
        }
        lst = lst->next;
    }
    move_to_top(stack_a, stack_b, min_node);
    pb(stack_a, stack_b);
}

void    stacka_to_stackb(t_list **stack_a, t_list **stack_b)
{
    int size_stack_a;

    size_stack_a = ft_lstsize(*stack_a);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    while (size_stack_a > 3)
    {
        get_target(stack_a, stack_b);
        costs(*stack_a);
        costs(*stack_b);
        push_node_minop(stack_a, stack_b);
        size_stack_a = ft_lstsize(*stack_a);
    }
}

void    push_node_minop_2(t_list **stack_b, t_list **stack_a)
{
    int min_op;
    t_list  *min_node;
    t_list  *lst;

    lst = *stack_b;
    min_op = lst->cost + lst->target->cost;
    min_node = lst;
    while (lst)
    {
        if (min_op > (lst->cost + lst->target->cost))
        {
            min_op = lst->cost + lst->target->cost;
            min_node = lst;
        }
        lst = lst->next;
    }
    move_to_top_2(stack_b, stack_a, min_node);
    pa(stack_a, stack_b);
}

void    stackb_to_stacka(t_list **stack_b, t_list **stack_a)
{
    int size_stack_b;

    size_stack_b = ft_lstsize(*stack_b);
    while (size_stack_b > 0)
    {
        get_target_2(stack_b, stack_a);
        costs(*stack_b);
        costs(*stack_a);
        push_node_minop_2(stack_b, stack_a);
        size_stack_b = ft_lstsize(*stack_b);
    }
}




// void    stackb_to_stacka(t_list **stack_b, t_list **stack_a)
// {
//     int size_stack_b;

//     size_stack_b = ft_lstsize(*stack_b);
//     while (size_stack_b > 0)
//     {
//         get_target_2(stack_b, stack_a);
//         costs(*stack_b);
//         costs(*stack_a);
//         ft_printf("%s\n", "\nstack     A");
//         print_list(*stack_a);
//         ft_printf("%s\n", "\nstack     B");
//         if (stack_b)
//             print_list(*stack_b);
//         push_node_minop_2(stack_b, stack_a);
//         ft_printf("%s\n", "\nstack     A");
//         print_list(*stack_a);
//         ft_printf("%s\n", "\nstack     B");
//         if (stack_b)
//             print_list(*stack_b);
//         size_stack_b = ft_lstsize(*stack_b);
//     }
// }
