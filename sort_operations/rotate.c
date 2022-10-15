/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:32:07 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/16 03:26:25 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **lst)
{
	t_stack	*tmp;
	
	if (!lst || !*lst || !((*lst)->next))
		return ;
	tmp = ft_lstlast(*lst);
	tmp->next = *lst;
	(*lst)->previous = tmp;
	tmp = (*lst)->next;
	(*lst)->next = NULL;
	*lst = tmp;
	(*lst)->previous = NULL;
}

void	ra(t_stack **lst)
{
	rotate(lst);
	write(1, "ra\n", 3);
}

void	rb(t_stack **lst)
{
	rotate(lst);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
