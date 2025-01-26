/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:28:02 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/24 18:11:05 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_repeat(t_list *head, int nb)
{
	t_list	*node = NULL;

	node = head;
	while (node)
	{
		if (node->content == nb)
			return (1);
		node = node->next;
	}
	return (0);
}

void print_list(t_list *lst)
{
    while (lst)
    {
        ft_printf("%d\n", lst->content);
        lst = lst->next;
    }
}

int is_num(char *ptr)
{
    if (!ptr || !*ptr)
        return (0);
    if (*ptr == '+' || *ptr == '-')
        ptr++;
    if (!*ptr)
        return (0);
    while (*ptr)
    {
        if (*ptr < '0' || *ptr > '9')
            return (0);
        ptr++;
    }
    return (1);
}

int	check_nb_put(t_list **head, char *ptr)
{
	int	resatoi;
	int	is_repeat;
	int overflow;

	is_repeat = 0;
	resatoi = 0;
	overflow = 0;
    if (is_num(ptr) == 0)
		return (ft_lstclear(head),0);
	resatoi = ft_atoi(ptr, &overflow);
	if (resatoi == 0 && overflow == 1)
		return (ft_lstclear(head),0);
    is_repeat = check_repeat(*head, resatoi);
    if (is_repeat == 1)
        return (ft_lstclear(head), 0);
    ft_lstadd_back(head, ft_lstnew((int)resatoi));
	return (1);
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

int split_check(char *arg, int argc, t_list **head)
{
	(void)argc;
	int	i;

	i = 0;
	char **ptr = NULL;
	ptr = ft_split(arg, ' ');
	if (!ptr)
		return 0;
	while (ptr[i])
	{
        if (check_nb_put(head, ptr[i]) == 0)
		{
			ft_freee(&ptr);
			return (0);
		}
		i++;
	}
	ft_freee(&ptr);
	return 1;
}

int main(int argc, char *argv[])
{
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	(void)argc;
	int i;
	
	i = 1;
	while (argv[i])
	{
		if (split_check(argv[i], argc, &stack_a) == 0)
		{
			ft_printf("%s\n", "Error");
			return (1);
		}
		i++;
	}
	int size = ft_lstsize(stack_a);

	if (size <= 5)
		sort_small_stack(&stack_a, &stack_b, size);
	else
	{
		stacka_to_stackb(&stack_a, &stack_b);
		sort_three(&stack_a);
		stackb_to_stacka(&stack_b, &stack_a);
	}
        
	ft_printf("%s\n", "\nstack     A");
	print_list(stack_a);
	ft_printf("%s\n", "stack     B");
	if (stack_b)
		print_list(stack_b);
	ft_lstclear(&stack_a);
    ft_lstclear(&stack_b);
	return (0);
}
