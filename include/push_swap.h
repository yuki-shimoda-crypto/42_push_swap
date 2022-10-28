/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:39:27 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/28 17:41:23 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

typedef struct s_stack
{
	int				num;
	long			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}			t_stack;

t_stack		*ft_lstnew(int num);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
size_t		ft_lstsize(t_stack *lst);
t_stack		*ft_lstfirst(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstdelone(t_stack *lst, void (*del)(int));
void		ft_lstclear(t_stack **lst, void (*del)(int));
void		ft_lstiter(t_stack *lst, void (*f)(int));
t_stack		*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int));
void		sa(t_stack **lst);
void		sb(t_stack **lst);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **lst);
void		rb(t_stack **lst);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **lst);
void		rrb(t_stack **lst);
void		rrr(t_stack **stack_a, t_stack **stack_b);
const char	**check_args(int argc, const char **argv);
void		coordinate_compression(t_stack *stack);
void		error_argv(char **str, int argc, long *num);
void		error_malloc(t_stack **stack);
void		free_str(void **num);
void		free_stack(t_stack **stack);
void		input_to_stack(int argc, const char **str, t_stack **stack);
bool		is_sorted(t_stack *stack);
void		radix_sort(t_stack **stack_a, t_stack **stack_b, size_t len);
void		scan_num(const char **str, int argc);
void		sort_stack(t_stack **stack_a, t_stack **stack_b);

void	radix_sort_three(t_stack **stack_a, t_stack **stack_b, size_t len);
#endif
