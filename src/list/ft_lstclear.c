/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:41:20 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 17:27:18 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*tmp;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		(*del)((*lst)->num);
		free(*lst);
		*lst = NULL;
		*lst = tmp->next;
	}
}
