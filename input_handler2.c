/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:47:45 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/02 10:49:59 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_repeat(t_list *head, int nb)
{
	t_list	*node;

	node = NULL;
	node = head;
	while (node)
	{
		if (node->content == nb)
			return (1);
		node = node->next;
	}
	return (0);
}

int	is_num(char *ptr)
{
	if (!ptr || !*ptr)
		return (0);
	if (*ptr == '+' || *ptr == '-')
		ptr++;
	if ((*ptr < '0' || *ptr > '9'))
		return (0);
	while (*ptr)
	{
		if (*ptr < '0' || *ptr > '9')
			return (0);
		ptr++;
	}
	return (1);
}
