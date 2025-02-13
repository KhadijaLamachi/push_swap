/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:05:09 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/08 21:12:24 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list{
	int				content;
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
void	push(t_list **src_stack, t_list **dst_stack);
// swap
void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
// rotate
void	rotate(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
// revrotate
void	revrotate(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
// utils
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr, int *overflow);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		is_sorted(t_list *stack);
// linked_list
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
// get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
// checker
void	execute_instructions(t_list **stack_a, t_list **stack_b);
void	rest_instructions(t_list **stack_a, t_list **stack_b, char **line);
#endif