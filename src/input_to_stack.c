/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 06:23:08 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/26 20:37:06 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	input_to_stack(int argc, const char **str, t_stack **stack)
{
	size_t	i;
	t_stack	*tmp;

	i = 1;
	if (argc == 2)
		i = 0;
	while (str[i])
	{
		tmp = ft_lstnew(ft_atoi(str[i]));
		if (!tmp && argc == 2)
			free_str((void **)str);
		if (!tmp)
			error_malloc(stack);
		ft_lstadd_back(stack, tmp);
		i++;
	}
	return ;
}
