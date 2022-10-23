/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:14:54 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 05:57:50 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate_error(t_stack **stack)
{
	t_stack	*tmp;

	while (stack && *stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = tmp;
	}
	ft_printf("Error. Duplicate arguments\n");
	exit(1);
}

void	error_argv(char **num, int argc)
{
	size_t	i;

	i = 0;
	if (argc == 2)
	{
		while (num[i])
			free(num[i++]);
		free(num);
	}
	ft_printf("Error. Argv error.\n");
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
	ft_printf("Error. Memory allocation error.\n");
	exit(1);
}
