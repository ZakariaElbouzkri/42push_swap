/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:38:58 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/15 11:19:59 by zel-bouz         ###   ########.fr       */
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
		if (stk->rank == mx->rank - 1)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
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
		push_max_to_b(vars);
}
