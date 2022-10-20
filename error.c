/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:14:54 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/19 23:43:54 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_argv(void)
{
	ft_printf("error argv\n");
	exit(1);
}

void	malloc_error(t_stack **stack)
{
	t_stack	*tmp;

	while (stack && *stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = tmp;
	}
	ft_printf("malloc_error\n");
	exit(1);
}
