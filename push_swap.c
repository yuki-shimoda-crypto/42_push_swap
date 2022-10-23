/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:14:37 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/19 22:46:14by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_num(void **num)
{
	size_t	i;

	i = 0;
	while (num[i])
	{
		free(num[i]);
		i++;
	}
	free(num);
}

static void	input_argv_to_stack(int argc, const char **num, t_stack **stack)
{
	size_t	i;
	t_stack	*tmp;

	i = 1;
	if (argc == 2)
		i = 0;
	while (num[i])
	{
		tmp = ft_lstnew(ft_atoi(num[i]));
		if (!tmp && argc == 2)
			free_num((void **)num);
		if (!tmp)
			malloc_error(stack);
		ft_lstadd_back(stack, tmp);
		i++;
	}
	return ;
}

int main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	const char	**num;
	
	stack_a = NULL;
	stack_b = NULL;
	num = check_args(argc, argv);
	if (!num)
		return (1);
	input_argv_to_stack(argc, num, &stack_a);
	if (num != argv)
		free_num((void **)num);
	sort_stack(&stack_a, &stack_b);
	// while (stack_a->next)
	// {
	// 	printf("%d\n", stack_a->num);
	// 	stack_a = stack_a->next;
	// }
	// stack_a = ft_lstfirst(stack_a);
	// while (stack_a)
	// {
	// 	printf("%d\n", stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	// while (1)
	// {
	// 	if (!stack_a)
	// 		break ;
	// 	printf("num\t\t%d\n", stack_a->num);
	// 	printf("index\t\t%ld\n", stack_a->index);
	// 	printf("stack_a\t\t%p\n", stack_a);
	// 	printf("previous\t%p\n", stack_a->previous);
	// 	printf("next\t\t%p\n", stack_a->next);
	// 	printf("-------------------\n");
	// 	if (!(stack_a->next))
	// 		break ;
	// 	stack_a = stack_a->next;
	// }
	// while (1)
	// {
	// 	if (!stack_b)
	// 		break ;
	// 	printf("num\t\t%d\n", stack_b->num);
	// 	printf("index\t\t%ld\n", stack_b->index);
	// 	printf("stack_b\t\t%p\n", stack_b);
	// 	printf("previous\t%p\n", stack_b->previous);
	// 	printf("next\t\t%p\n", stack_b->next);
	// 	printf("-------------------\n");
	// 	if (!(stack_b->next))
	// 		break ;
	// 	stack_b = stack_b->next;
	// }
	return (0);
}
