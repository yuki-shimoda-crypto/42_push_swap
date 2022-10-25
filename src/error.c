/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:14:54 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/25 17:57:56 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
	ft_putstr_fd("Error. Duplicate arguments\n", 2);
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
	ft_putstr_fd("Error. Argv error.\n", 2);
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
	ft_putstr_fd("Error. Memory allocation error.\n", 2);
	exit(1);
}
