/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:41:13 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 21:42:37 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stk	*max_elem_node(t_stk *stk)
{
	int	max;

	max = max_element(stk);
	while (stk)
	{
		if (stk->data == max)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

t_stk	*min_elem_node(t_stk *stk)
{
	int	min;

	min = min_element(stk);
	while (stk)
	{
		if (stk->data == min)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

t_stk	*uninitialized_max(t_stk *stk)
{
	t_stk	*max;
	int		m;

	max = stk;
	while (max)
	{
		if (max->rank == 0)
			break ;
		max = max->next;
	}
	m = max->data;
	while (stk)
	{
		if (stk->data > m && stk->rank == 0)
		{
			max = stk;
			m = stk->data;
		}
		stk = stk->next;
	}
	return (max);
}

int	max_element(t_stk *a)
{
	int	max;

	if (!a)
		return (0);
	max = a->data;
	while (a)
	{
		if (a->data > max)
			max = a->data;
		a = a->next;
	}
	return (max);
}

int	min_element(t_stk *a)
{
	int	min;

	if (!a)
		return (INT_MAX);
	min = a->data;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	return (min);
}
