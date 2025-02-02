/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:54:14 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/02 22:33:41 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_list **head)
{
	ft_lstclear(head);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_nb_put(t_list **head, char *ptr)
{
	int	resatoi;
	int	is_repeat;
	int	overflow;

	is_repeat = 0;
	resatoi = 0;
	overflow = 0;
	if (is_num(ptr) == 0)
		exit_with_error(head);
	resatoi = ft_atoi(ptr, &overflow);
	if (resatoi == 0 && overflow == 1)
		exit_with_error(head);
	is_repeat = check_repeat(*head, resatoi);
	if (is_repeat == 1)
		exit_with_error(head);
	ft_lstadd_back(head, ft_lstnew((int)resatoi));
}

static void	ft_freee(char ***ptr)
{
	int	i;

	i = 0;
	while ((*ptr)[i])
	{
		free((*ptr)[i]);
		i++;
	}
	free(*ptr);
	*ptr = NULL;
}

void	handle_input(char **argv, t_list **stack_a)
{
	int		i;
	int		j;
	char	**ptr;

	i = 1;
	while (argv[i])
	{
		j = 0;
		ptr = ft_split(argv[i], ' ');
		if (!ptr || !*ptr)
			exit_with_error(stack_a);
		while (ptr[j])
		{
			check_nb_put(stack_a, ptr[j]);
			j++;
		}
		ft_freee(&ptr);
		i++;
	}
}
