/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:16:57 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/23 17:17:19by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b, size_t len)
{
	t_stack	*tmp;
	size_t	count;
	// size_t	tmp;
	size_t	base;
	size_t	i;
	size_t	j;


	count = len;
	base = 2;
	i = 0;
	tmp = *stack_a;
	while (i < 32)
	{
		j = 0;
		if (!is_sorted(*stack_a))
			break ;
		while (j < len)
		{
			if (!((*stack_a)->index & ((1) << (i))))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		base *= 2;
		i++;
	}
	// *stack_a = ft_lstfirst(tmp);

	// while (1)
	// {
	// 	if (!*stack_a)
	// 		break ;
	// 	printf("num\t\t%d\n", (*stack_a)->num);
	// 	printf("index\t\t%ld\n", (*stack_a)->index);
	// 	printf("stack_a\t\t%p\n", *stack_a);
	// 	printf("previous\t%p\n", (*stack_a)->previous);
	// 	printf("next\t\t%p\n", (*stack_a)->next);
	// 	printf("-------------------\n");
	// 	if (!((*stack_a)->next))
	// 		break ;
	// 	*stack_a = (*stack_a)->next;
	// }
	// *stack_b = ft_lstfirst(*stack_b);
	// while (1)
	// {
	// 	if (!*stack_b)
	// 		break ;
	// 	printf("num\t\t%d\n", (*stack_b)->num);
	// 	printf("index\t\t%ld\n", (*stack_b)->index);
	// 	printf("stack_b\t\t%p\n", *stack_b);
	// 	printf("previous\t%p\n", (*stack_b)->previous);
	// 	printf("next\t\t%p\n", (*stack_b)->next);
	// 	printf("-------------------\n");
	// 	if (!((*stack_b)->next))
	// 		break ;
	// 	*stack_b = (*stack_b)->next;
	// }
	return ;
}
