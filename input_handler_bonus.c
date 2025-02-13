/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:04:46 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/08 21:42:32 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exit_with_error(t_list **head)
{
	ft_lstclear(head);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_nb_put(t_list **head, char *ptr)
{
	int	resatoi;
	int	is_repeat;
	int	overflow;

	is_repeat = 0;
	resatoi = 0;
	overflow = 0;
	if (is_num(ptr) == 0)
		return (1);
	resatoi = ft_atoi(ptr, &overflow);
	if (resatoi == 0 && overflow == 1)
		return (1);
	is_repeat = check_repeat(*head, resatoi);
	if (is_repeat == 1)
		return (1);
	ft_lstadd_back(head, ft_lstnew((int)resatoi));
	return (0);
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
	char	**ptr;

	int (i), (j);
	i = 1;
	while (argv[i])
	{
		j = 0;
		ptr = ft_split(argv[i], ' ');
		if (!ptr || !*ptr)
		{
			free(ptr);
			exit_with_error(stack_a);
		}
		while (ptr[j])
		{
			if (check_nb_put(stack_a, ptr[j]) == 1)
			{
				ft_freee(&ptr);
				exit_with_error(stack_a);
			}
			j++;
		}
		ft_freee(&ptr);
		i++;
	}
}
