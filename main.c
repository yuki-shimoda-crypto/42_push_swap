/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:55:05 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/19 16:55:43by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int	i;

	i = 0;
	while (1)
	{
		printf("%s\n", argv[i]);
		i++;
		if (!argv[i])
			break ;
	}
	return (0);
}
