/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:08:58 by klamachi          #+#    #+#             */
/*   Updated: 2025/01/24 14:55:48 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
// #include <stdio.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"

typedef struct s_list{
	int content;
	struct s_list *next;
	struct s_list *target;
	int	cost;
}t_list;

int	ft_printf(const char *s, ...);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int ft_lstsize(t_list *lst);
int ft_atoi(const char *nptr, int *overflow);
int	check_repeat(t_list *head, int nb);
size_t	ft_strlen(const char *s);
int	check_nb_put(t_list **head, char *ptr);
int split_check(char *arg, int argc, t_list **head);
char	**ft_split(char const *s, char c);
// void	ft_free(char ***ptr, int k);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);


void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a ,t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// void sort_small_stack(t_list **stack_a);
void	sort_small_stack(t_list **stack_a, t_list **stack_b, int size);
void    stacka_to_stackb(t_list **stack_a, t_list **stack_b);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);





// void print_list_target(t_list *lst);

void    stacka_to_stackb(t_list **stack_a, t_list **stack_b);
void    stackb_to_stacka(t_list **stack_b, t_list **stack_a);
void    push_node_minop(t_list **stack_a, t_list **stack_b);
void    push_node_minop_2(t_list **stack_b, t_list **stack_a);
void    move_to_top(t_list **stack_a, t_list **stack_b, t_list *min_node);
void    move_to_top_2(t_list **stack_b, t_list **stack_a, t_list *min_node);
void	costs(t_list *stack);
void	get_target(t_list **stack_a, t_list	**stack_b);
void	get_target_2(t_list **stack_b, t_list	**stack_a);



void print_list(t_list *lst);

#endif // PUSH_SWAP_H