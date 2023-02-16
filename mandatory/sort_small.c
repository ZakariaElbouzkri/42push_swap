/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:38:34 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/15 03:47:24 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_vars *vars)
{
	t_stk	*max;
	t_stk	*min;

	min = min_elem_node(vars->a);
	max = max_elem_node(vars->a);
	if (vars->a->data == max->data)
	{
		exec_ra(&vars->a);
		if (vars->a->data != min->data)
			exec_sa(vars->a);
	}
	else if (vars->a->data == min->data)
	{
		exec_rra(&vars->a);
		exec_sa(vars->a);
	}
	else
	{
		if (vars->a->next->data == max->data)
			exec_rra(&vars->a);
		else
			exec_sa(vars->a);
	}
}

void	sort_five(t_vars *vars)
{
	if (vars->a_len == 5)
		push_min(vars);
	push_min(vars);
	if (!stack_sorted(vars->a))
		sort_three(vars);
	while (vars->b)
		exec_pa(&vars->b, &vars->a);
}

void	sort_small(t_vars *vars)
{
	if (!stack_sorted(vars->a))
	{
		if (vars->a_len == 2)
			exec_sa(vars->a);
		else if (vars->a_len == 3)
			sort_three(vars);
		else if (vars->a_len <= 5)
			sort_five(vars);
	}
}
