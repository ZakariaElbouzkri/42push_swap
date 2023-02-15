/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:40:26 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/15 03:23:34 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calc_moves(int pos1, int pos2, int len)
{
	int	midle;

	midle = len / 2;
	if (pos1 > midle)
		pos1 = len - pos1;
	if (pos2 > midle)
		pos2 = len - pos2;
	if (pos1 > pos2)
		return (pos2);
	return (pos1);
}

void	push_min(t_vars *vars)
{
	t_stk	*min;

	min = min_elem_node(vars->a);
	while (vars->a->rank != min->rank)
	{
		if (min->pos > (vars->a_len / 2))
		{
			while (vars->a->rank != min->rank)
				exec_rra(&vars->a);
			break ;
		}
		else
		{
			while (vars->a->rank != min->rank)
				exec_ra(&vars->a);
			break ;
		}
	}
	exec_pb(&vars->a, &vars->b);
	vars->a_len--;
}

t_stk	*node_by_pos(t_stk *stk, int pos)
{
	while (stk)
	{
		if (stk->pos == pos)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

void	push_closest_nbr(t_vars *vars, int pos)
{
	int		i;
	t_stk	*node;

	i = 0;
	node = node_by_pos(vars->a, pos);
	if (pos > vars->a_len / 2)
	{
		while (vars->a->data != node->data)
		{
			exec_rra(&vars->a);
			i++;
		}
	}
	if (pos <= vars->a_len / 2)
	{
		while (vars->a->data != node->data)
		{
			exec_ra(&vars->a);
			i++;
		}	
	}
	exec_pb(&vars->a, &vars->b);
	vars->a_len--;
	vars->b_len++;
	rotate_b(vars);
}

void	init_final_pos(t_stk *stk)
{
	t_stk	*max;
	int		i;
	int		stk_len;

	i = 1;
	stk_len = stk_size(stk);
	max = max_elem_node(stk);
	max->rank = stk_len;
	while (i < stk_len)
	{
		max = uninitialized_max(stk);
		max->rank = stk_len - i;
		i++;
	}
}
