/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:16:59 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/26 20:36:01 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

const char	**check_args(int argc, const char **argv)
{
	const char	**str;

	if (argc < 2)
		exit(1);
	else if (argc == 2)
	{
		str = (const char **)ft_split(argv[1], ' ');
		if (!str)
			error_malloc(NULL);
	}
	else
		str = argv;
	scan_num(str, argc);
	return (str);
}
