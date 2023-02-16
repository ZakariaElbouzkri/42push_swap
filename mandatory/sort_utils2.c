/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 03:21:48 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/16 04:32:18 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_elem(t_vars *vars, t_stk *node, int size)
{
	if (node->pos <= size / 2)
	{
		while (vars->b->data != node->data)
			exec_rb(&vars->b);
		exec_pa(&vars->b, &vars->a);
	}
	else if (node->pos > size / 2)
	{
		while (vars->b->data != node->data)
			exec_rrb(&vars->b);
		exec_pa(&vars->b, &vars->a);
	}
	vars->b_len--;
	vars->a_len++;
}

void	fix_un_mx_pos(t_vars *vars)
{
	if (vars->a_len > 1 && vars->a->data > vars->a->next->data)
	{
		if (vars->b_len > 1 && vars->b->data < vars->b->next->data)
		{
			exec_ss(vars->a, vars->b);
			return ;
		}
		exec_sa(vars->a);
	}
}

void	push_max_to_b(t_vars *vars)
{
	t_stk	*mx;
	t_stk	*ud_mx;
	int		cost1;
	int		cost2;

	cost1 = 1;
	cost2 = 1;
	mx = max_elem_node(vars->b);
	ud_mx = under_max_node(vars->b, mx);
	if (mx->pos > vars->b_len / 2)
		cost1 = vars->b_len - mx->pos;
	else if (mx->pos <= vars->b_len / 2)
		cost1 = mx->pos;
	if (ud_mx && ud_mx->pos > vars->b_len / 2)
		cost2 = vars->b_len - ud_mx->pos;
	else if (ud_mx && ud_mx->pos <= vars->b_len / 2)
		cost2 = ud_mx->pos;
	if (cost1 <= (cost2) || !ud_mx)
		push_elem(vars, mx, vars->b_len);
	else
		push_elem(vars, ud_mx, vars->b_len);
	fix_un_mx_pos(vars);
}

