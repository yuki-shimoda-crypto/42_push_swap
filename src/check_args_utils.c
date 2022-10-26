/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:33:12 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/26 20:52:55 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static bool	check_isdup(long *num, size_t elems)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < elems)
	{
		j = i + 1;
		while (j < elems)
		{
			if (num[i] == num[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	check_isover_int(long num)
{
	if (num < INT_MIN)
		return (true);
	if (INT_MAX < num)
		return (true);
	return (false);
}

static bool	check_isnum(const char *s)
{
	if (!s)
		return (false);
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (false);
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (false);
	}
	return (true);
}

static size_t	count_elem(const char **str, int argc)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	if (argc != 2)
		i -= 1;
	return (i);
}

void	scan_num(const char **str, int argc)
{
	size_t	i;
	size_t	j;
	size_t	elems;
	long	*num;

	i = 1;
	if (argc == 2)
		i = 0;
	elems = count_elem(str, argc);
	num = malloc(sizeof(long) * elems);
	if (!num)
		error_malloc(NULL);
	j = 0;
	while (str[i])
	{
		num[j] = ft_atol(str[i]);
		if (!check_isnum(str[i]) || check_isover_int(num[j]))
			error_argv((char **)str, argc, num);
		i++;
		j++;
	}
	if (check_isdup(num, elems))
		error_argv((char **)str, argc, num);
	free(num);
}
