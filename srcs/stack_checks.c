/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:50:43 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 19:54:42 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static int ft_str_is_digit(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '-')
			return (0);
		s++;
	}
	return (1);
}

void    check_error(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (!ft_str_is_digit(arr[i]))
			ft_puterror("Wrng, anly digits are allowed");
		i++;
	}
}

void    check_dup(char **arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (!ft_strcmp(arr[i], arr[j]))
				ft_puterror("Wrong, duplicated args");
			j++;
		}
		i++;
	}
}

int    check_is_sorted(t_stk *a)
{
	int i;
	int j;
	int triger;

	triger = 1;
	while (a->next)
	{
		i = a->num;
		j = a->next->num;
		if (i > j)
			triger = 0;
		a = a->next;
	}
	return (triger);
}