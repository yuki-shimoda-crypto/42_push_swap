/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:46:47 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/02 15:46:49 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_pow(size_t exp, size_t pow)
{
	size_t	num;

	num = 1;
	while (pow--)
		num *= exp;
	return (num);
}

void	radix_sort_three(t_stack **stack_a, t_stack **stack_b, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (1)
	{
		if (is_sorted(*stack_a))
			break ;
		j = 0;
		while (j < len)
		{
			if (((*stack_a)->index / ft_pow(3, i)) % 3 == 0)
				pb(stack_a, stack_b);
			else if (((*stack_a)->index / ft_pow(3, i)) % 3 == 1)
			{
				pb(stack_a, stack_b);
				rb(stack_b);
				printf("%zu\n", ft_pow(3, i));
			}
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
