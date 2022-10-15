/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:42:00 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/15 22:05:01 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = -1;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
int main(void)
{
	t_stack	*ptr;

	ptr = ft_lstnew(1);
	printf("%d\n", ptr->num);
	free(ptr);
	ptr = NULL;
	return 0;
}
