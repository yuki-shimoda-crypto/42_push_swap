/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:31:25 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/16 13:25:24 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

// int main(void)
// {
// 	t_stack *lst;
// 	t_stack *lst2;

// 	lst = ft_lstnew(1);
// 	lst2 = ft_lstnew(2);
// 	ft_lstadd_back(&lst, lst2);
// 	lst = ft_lstfirst(lst);
// 	ft_lstadd_front(&lst, ft_lstnew(0));
// 	while (1)
// 	{
// 		printf("num\t\t%d\n", lst->num);
// 		printf("index\t\t%ld\n", lst->index);
// 		printf("lst\t\t%p\n", lst);
// 		printf("previous\t%p\n", lst->previous);
// 		printf("next\t\t%p\n", lst->next);
// 		printf("-------------------\n");
// 		if (!(lst->next))
// 			break ;
// 		lst = lst->next;
// 	}
// 	printf("%d\n", ft_lstsize(ft_lstfirst(lst)));
	
// 	return (0);
// }

#include <stdio.h>

int main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_lstnew(0);
	stack_b = ft_lstnew(1);
	stack_a = ft_lstfirst(stack_a);
	stack_b = ft_lstfirst(stack_b);
	// ft_lstadd_back(&stack_a, ft_lstnew(2));
	// ft_lstadd_back(&stack_b, ft_lstnew(3));
	// ft_lstadd_back(&stack_a, ft_lstnew(4));
	// ft_lstadd_back(&stack_b, ft_lstnew(5));
	// sa(&stack_a);
	// sb(&stack_b);
	// ss(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// ra(&stack_a);
	// rb(&stack_b);
	// rr(&stack_a, &stack_b);
	// rra(&stack_a);
	// rrb(&stack_b);
	// rrr(&stack_a, &stack_b);
	while (1)
	{
		if (!stack_a)
			break ;
		printf("num\t\t%d\n", stack_a->num);
		printf("index\t\t%ld\n", stack_a->index);
		printf("stack_a\t\t%p\n", stack_a);
		printf("previous\t%p\n", stack_a->previous);
		printf("next\t\t%p\n", stack_a->next);
		printf("-------------------\n");
		if (!(stack_a->next))
			break ;
		stack_a = stack_a->next;
	}

	while (1)
	{
		if (!stack_b)
			break ;
		printf("num\t\t%d\n", stack_b->num);
		printf("index\t\t%ld\n", stack_b->index);
		printf("stack_b\t\t%p\n", stack_b);
		printf("previous\t%p\n", stack_b->previous);
		printf("next\t\t%p\n", stack_b->next);
		printf("-------------------\n");
		if (!(stack_b->next))
			break ;
		stack_b = stack_b->next;
	}
	
	return (0);
}
