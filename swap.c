/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:08:00 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/23 22:05:52 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **stack_a)
{
    t_list *tmp;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    tmp = (*stack_a)->next;
    (*stack_a)->next = tmp->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    ft_printf("sa\n");
}

void sb(t_list **stack_b)
{
    t_list *tmp;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    tmp = (*stack_b)->next;
    (*stack_b)->next = tmp->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    ft_printf("sb\n");
}

void use_sa(t_list **stack_a)
{
    t_list *tmp;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    tmp = (*stack_a)->next;
    (*stack_a)->next = tmp->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void use_sb(t_list **stack_b)
{
    t_list *tmp;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    tmp = (*stack_b)->next;
    (*stack_b)->next = tmp->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
}

void ss(t_list **stack_a ,t_list **stack_b)
{
    use_sa(stack_a);
    use_sb(stack_b);
    ft_printf("ss\n");
}