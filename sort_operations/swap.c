/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:32:02 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/16 01:50:42 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)-> next;
	first->previous = second;
	first->next = second->next;
	second->previous = NULL;
	second->next = first;
	*lst = second;
}

void	sa(t_stack **lst)
{
	swap(lst);
	write(1, "sa\n", 3);
}

void	sb(t_stack **lst)
{
	swap(lst);
	write(1, "sb\n", 3);
}

void	ss(t_stack **sa, t_stack **sb)
{
	swap(sa);
	swap(sb);
	write(1, "ss\n", 3);
}

#include <stdio.h>

int main(void)
{
	/* code */
	return (0);
}