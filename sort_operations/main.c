/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:31:25 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/16 07:04:31 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int main(void)
{
	t_stack *lst;
	t_stack *lst2;

	lst = ft_lstnew(1);
	lst2 = ft_lstnew(2);
	ft_lstadd_back(&lst, lst2);
	lst = ft_lstfirst(lst);
	ft_lstadd_front(&lst, ft_lstnew(0));
	while (1)
	{
		printf("num\t\t%d\n", lst->num);
		printf("index\t\t%ld\n", lst->index);
		printf("lst\t\t%p\n", lst);
		printf("previous\t%p\n", lst->previous);
		printf("next\t\t%p\n", lst->next);
		printf("-------------------\n");
		if (!(lst->next))
			break ;
		lst = lst->next;
	}
	printf("%d\n", ft_lstsize(ft_lstfirst(lst)));
	
	return (0);
}
