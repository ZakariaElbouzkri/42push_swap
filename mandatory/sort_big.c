/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:38:58 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/14 08:15:33 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_b(t_vars *vars)
{
	int	prefix;

	prefix = (vars->fixe_len / vars->shunks_nm) / 2;
	if (vars->b->rank < vars->pivot - prefix)
	{
		if (vars->a_len > 1 && vars->a->data > vars->a->next->data)
		{
			exec_rr(&vars->a, &vars->b);
			return ;
		}
		exec_rb(&vars->b);
	}
}
int	closest_nbr_of_chunk(t_vars *vars)
{
	t_stk	*stk;
	int		pos1;
	int		pos2;
	int		i;

	stk = vars->a;
	i = 0;
	while (stk)
	{
		if (!i && stk->rank <= vars->pivot)
		{
			pos1 = stk->pos;
			i++;
		}
		else if (i && stk->rank <= vars->pivot)
			pos2 = stk->pos;
		stk = stk->next;
	}
	if (pos1 > vars->a_len - pos2)
		return (pos2);
	return (pos1);
}

t_stk	*under_max_node(t_stk *stk, t_stk *mx)
{
	while (stk)
	{
		if (stk->data == mx->data - 1)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

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

void	push_maxb(t_vars *vars)
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

void	chunk_algo(t_vars *vars)
{
	int	pos1;
	int	i;
	int	pivot;

	i = 1;
	pivot = vars->pivot;
	while (vars->a)
	{
		pos1 = closest_nbr_of_chunk(vars);
		push_closest_nbr(vars, pos1);
		i++;
		if (i == vars->pivot)
			vars->pivot += pivot;
	}
	while (vars->b)
	{
		// push_max(&vars->a, &vars->b, vars->b_len);
		push_maxb(vars);
	}
	// print_list(vars->a);
}
