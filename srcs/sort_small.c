/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:21:16 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 19:54:28 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stk **a)
{
	sa_b_op(a, "sa\n");
}

void	sort_three(t_stk **a)
{
	int min;
	int max;

	min = min_element(*a);
	max = max_element(*a);
	if ((*a)->num == min)
	{
		sa_b_op(a, "sa\n");
		ra_b_op(a, "ra\n");
	}
	else if ((*a)->num == max)
	{
		ra_b_op(a, "ra\n");
		if ((*a)->num > (*a)->next->num)
			sa_b_op(a, "sa\n");
	}
	else 
	{
		if ((*a)->next->num > (*a)->next->next->num)
			rra_b_op(a, "rra\n");
		else
			sa_b_op(a, "sa\n");
	}
}

void	sort_four(t_stk **a, t_stk **b)
{
	int min;

	min = min_element(*a);

	while ((*a)->num != min)
	{
		if ((*a)->next->num == min)
		{
			sa_b_op(a, "sa\n");
			break;
		}
		rra_b_op(a, "rra\n");
	}
	pa_b_op(a, b, "pb\n");
	if (!check_is_sorted(*a))
		sort_three(a);
	pa_b_op(b, a, "pa\n");
}

void sort_five(t_stk **a, t_stk **b)
{
	push_min_pb(a, b);
	push_min_pb(a, b);
	if (!check_is_sorted(*a))
		sort_three(a);
	pa_b_op(b, a, "pa\n");
	pa_b_op(b, a, "pa\n");
}


void    sort_small(t_stk **a, t_stk **b)
{
    int a_len;

    a_len = ft_stack_size(*a);
    if (a_len == 2)
        sort_two(a);
    else if (a_len == 3)
        sort_three(a);
    else if (a_len == 4)
        sort_four(a, b);
    else if (a_len == 5)
        sort_five(a, b);
}