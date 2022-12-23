/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:23:49 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 19:54:36 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	min_element(t_stk *a)
{
	int min;

	min = a->num;
	while (a)
	{
		if (a->num < min)
			min = a->num;
		a = a->next;
	}
	return (min);
}

int max_element(t_stk *a)
{
	int max;

	max = a->num;
	while (a)
	{
		if (a->num > max)
			max = a->num;
		a = a->next;
	}
	return (max);
}

int index_of_elem(t_stk *a, int m)
{
	int indx;

	indx = 0;
	while (a)
	{
		if (a->num == m)
			return (indx);
		indx++;
		a = a->next;
	}
	return (indx);
}

void	push_min_pb(t_stk **a, t_stk **b)
{
	int min;
	int len;

	min = min_element(*a);
	len = ft_stack_size(*a);
	while ((*a)->num != min)
	{
		if (index_of_elem(*a, min) >= (len / 2))
		{
			while ((*a)->num != min)
				rra_b_op(a, "rra\n");
			break;
		}
		if (index_of_elem(*a, min) < (len / 2))
		{
			while ((*a)->num != min)
				ra_b_op(a, "ra\n");
			break;
		}
	}
	pa_b_op(a, b, "pb\n");
}