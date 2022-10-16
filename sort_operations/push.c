/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:31:25 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/16 13:27:25 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **send, t_stack **receive)
{
	t_stack	*tmp_send;

	if (!send || !receive || !*send)
		return ;
	tmp_send = *send;
	if (!(*send)->next)
		*send = NULL;
	else
	{
		*send = (*send)->next;
		(*send)->previous = NULL;
	}
	if (*receive)
	{
		(*receive)->previous = tmp_send;
		tmp_send->next = *receive;
		*receive = tmp_send;
	}
	else
	{
		*receive = tmp_send;
		(*receive)->next = NULL;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
