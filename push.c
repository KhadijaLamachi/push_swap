/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:58:57 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/07 17:20:29 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src_stack, t_list **dst_stack, char *operation)
{
	t_list	*tmp;

	if (!*src_stack)
		return ;
	tmp = *src_stack;
	*src_stack = (*src_stack)->next;
	tmp->next = *dst_stack;
	*dst_stack = tmp;
	if (operation && ft_strcmp(operation, "pa") == 0)
		write(1, "pa\n", 3);
	else if (operation && ft_strcmp(operation, "pb") == 0)
		write(1, "pb\n", 3);
}
