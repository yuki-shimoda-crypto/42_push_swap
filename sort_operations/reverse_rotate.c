/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:31:53 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/16 03:45:23 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **lst)
{
	t_stack	*tmp;
	
	if (!lst || !*lst || !((*lst)->next))
		return ;
	tmp = ft_lstlast(*lst);
	tmp->next = *lst;
	(*lst)->previous = tmp;
	*lst = tmp;
	tmp = tmp->previous;
	tmp->next = NULL;
	(*lst)->previous = NULL;
}

void	rra(t_stack **lst)
{
	reverse_rotate(lst);
	write(1, "rra\n", 3);
}

void	rrb(t_stack **lst)
{
	reverse_rotate(lst);
	write(1, "rrb\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 3);
}

// int main()
// {
// 	/* code */
// 	return 0;
// }
