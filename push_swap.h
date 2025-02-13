/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:52:49 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/08 12:30:14 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list{
	int				content;
	int				bellowmed;
	int				rank;
	struct s_list	*target;
	int				cost;
	struct s_list	*next;
}t_list;
// input_handler
int		check_repeat(t_list *head, int nb);
int		is_num(char *ptr);
int		check_nb_put(t_list **head, char *ptr);
void	handle_input(char **argv, t_list **stack_a);
void	exit_with_error(t_list **head);
// operations
// push
void	push(t_list **src_stack, t_list **dst_stack, char *operation);
// swap
void	swap(t_list **stack, char *operation);
void	ss(t_list **stack_a, t_list **stack_b);
// rotate
void	rotate(t_list **stack, const char *operation);
void	rr(t_list **stack_a, t_list **stack_b);
// revrotate
void	revrotate(t_list **stack, const char *operation);
void	rrr(t_list **stack_a, t_list **stack_b);
// sort_stack
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_small_stack(t_list **stack_a, int size);
void	sort_three(t_list **stack_a);
void	sort_two(t_list **stack_a);
// utils
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr, int *overflow);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*find_min(t_list *stack);
void	is_bellowmed(t_list *stack, t_list *node);
int		is_sorted(t_list *stack);
// linked_list
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
// sort few args
void	sort_small_stack(t_list **stack_a, int size);
// rank
void	get_rank(t_list **head);
void	push_by_rank(t_list **stacka, t_list **stackb);
void	push_to_b(t_list **stack_a, t_list **stack_b);
// turk
void	target(t_list **stack_a, t_list **stack_b);
void	cost(t_list *stack);
void	sum_costs(t_list *stack_b);
void	move_to_top(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);
t_list	*cheapest(t_list *stack_b);
void	push_to_a(t_list **stack_a, t_list **stack_b);
#endif