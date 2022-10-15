/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:31:25 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/16 06:41:12 by yshimoda         ###   ########.fr       */
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
	printf("%d\n", lst->num);
	printf("%ld\n", lst->index);
	printf("%p\n", lst->next);
	printf("%p\n", lst->previous);
	lst = lst->next;
	printf("%d\n", lst->num);
	printf("%ld\n", lst->index);
	printf("%p\n", lst->next);
	printf("%p\n", lst->previous);
	return (0);
}