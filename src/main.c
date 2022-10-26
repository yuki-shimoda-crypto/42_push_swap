/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:43:31 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/26 20:45:07 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	const char	**str;

	stack_a = NULL;
	stack_b = NULL;
	str = check_args(argc, argv);
	input_to_stack(argc, str, &stack_a);
	if (str != argv)
		free_str((void **)str);
	coordinate_compression(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }
