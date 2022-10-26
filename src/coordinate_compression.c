/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:28:34 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/26 20:28:54 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	coordinate_compression(t_stack *stack)
{
	t_stack	*min;
	t_stack	*tmp;
	size_t	i;
	size_t	len;
	int		max;

	i = 0;
	len = ft_lstsize(stack);
	while (i < len)
	{
		max = INT_MAX;
		tmp = stack;
		while (tmp)
		{
			if (tmp->num <= max && tmp->index == -1)
			{
				max = tmp->num;
				min = tmp;
			}
			tmp = tmp->next;
		}
		min->index = i;
		i++;
	}
}
