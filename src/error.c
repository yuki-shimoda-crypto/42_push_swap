/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:14:54 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/26 20:44:34 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	error_argv(char **str, int argc, long *num)
{
	size_t	i;

	i = 0;
	if (argc == 2)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
	free(num);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_malloc(t_stack **stack)
{
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
