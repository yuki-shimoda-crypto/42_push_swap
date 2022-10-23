/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 06:29:28 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 06:29:44 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_stack **stack)
{
	while (is_sorted(*stack))
	{
		if ((*stack)->index < (*stack)->next->next->index)
			sa(stack);
		else
			ra(stack);
	}
}

static void	five_sort(t_stack **stack_a, t_stack **stack_b, size_t len)
{
	while (ft_lstsize(*stack_a) != 3)
	{
		if ((*stack_a)->index < (long)(len - 3))
			pb(stack_a, stack_b);
		else if ((*stack_a)->next->index < (long)(len - 3) ||
			(*stack_a)->next->next->index < (long)(len - 3))
			ra(stack_a);
		else
			rra(stack_a);
	}
	three_sort(stack_a);
	if (!is_sorted(*stack_b))
		sb(stack_b);
	while (len - 3)
	{
		pa(stack_a, stack_b);
		len--;
	}
	return ;
}

static void	coordinate_compression(t_stack *stack, size_t len)
{
	t_stack	*min;
	t_stack	*tmp;
	size_t	i;
	int		max;

	i = 0;
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

static int	check_dup(t_stack *stack)
{
	t_stack	*tmp;

	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->num == tmp->num)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	size_t	len;

	if (check_dup(*stack_a))
		duplicate_error(stack_a);
	len = ft_lstsize(*stack_a);
	coordinate_compression(*stack_a, len);
	if (!is_sorted(*stack_a))
		return ;
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		three_sort(stack_a);
	else if (len <= 5)
		five_sort(stack_a, stack_b, len);
	else
		radix_sort(stack_a, stack_b, len);
}
