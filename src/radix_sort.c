/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 06:29:59 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 06:30:02 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (1)
	{
		if (!is_sorted(*stack_a))
			break ;
		j = 0;
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
		i++;
	}
	return ;
}
