/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:31:25 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 17:32:32 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// #include <stdio.h>
// #include "push_swap.h"

// int main(void)
// {
// 	t_stack	*stack_a = NULL;
// 	t_stack	*stack_b = NULL;

// 	stack_a = ft_lstnew(0);
// 	stack_b = ft_lstnew(1);
// 	stack_a = ft_lstfirst(stack_a);
// 	stack_b = ft_lstfirst(stack_b);
// 	ft_lstadd_back(&stack_a, ft_lstnew(2));
// 	ft_lstadd_back(&stack_b, ft_lstnew(3));
// 	ft_lstadd_back(&stack_a, ft_lstnew(4));
// 	ft_lstadd_back(&stack_b, ft_lstnew(5));
// 	sa(&stack_a);
// 	sb(&stack_b);
// 	ss(&stack_a, &stack_b);
// 	pa(&stack_a, &stack_b);
// 	pb(&stack_a, &stack_b);
// 	pa(&stack_a, &stack_b);
// 	ra(&stack_a);
// 	rb(&stack_b);
// 	rr(&stack_a, &stack_b);
// 	rra(&stack_a);
// 	rrb(&stack_b);
// 	rrr(&stack_a, &stack_b);
// 	while (1)
// 	{
// 		if (!stack_a)
// 			break ;
// 		printf("num\t\t%d\n", stack_a->num);
// 		printf("index\t\t%ld\n", stack_a->index);
// 		printf("stack_a\t\t%p\n", stack_a);
// 		printf("previous\t%p\n", stack_a->previous);
// 		printf("next\t\t%p\n", stack_a->next);
// 		printf("-------------------\n");
// 		if (!(stack_a->next))
// 			break ;
// 		stack_a = stack_a->next;
// 	}
// 	while (1)
// 	{
// 		if (!stack_b)
// 			break ;
// 		printf("num\t\t%d\n", stack_b->num);
// 		printf("index\t\t%ld\n", stack_b->index);
// 		printf("stack_b\t\t%p\n", stack_b);
// 		printf("previous\t%p\n", stack_b->previous);
// 		printf("next\t\t%p\n", stack_b->next);
// 		printf("-------------------\n");
// 		if (!(stack_b->next))
// 			break ;
// 		stack_b = stack_b->next;
// 	}
// 	return (0);
// }