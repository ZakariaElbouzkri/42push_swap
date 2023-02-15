/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:03:27 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/14 06:28:36 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_chunks_nm(int size)
{
	int nbr_of_chunks;

	nbr_of_chunks = 1;
	if (size > 10)
		nbr_of_chunks = size / 2;
	else if (size > 50)
		nbr_of_chunks = size / 15;
	else if (size >= 100)
		nbr_of_chunks = size / 20;
	else if (size >= 500)
		nbr_of_chunks = size / 50;
	return (nbr_of_chunks);
}

void    plen_vars(t_vars *vars)
{
	vars->a_len = stk_size(vars->a);
	vars->fixe_len = vars->a_len;
	vars->shunks_nm = get_chunks_nm(vars->a_len);
	vars->pv = vars->a_len / vars->shunks_nm;
}

t_stk	*get_top_in_chunk(t_stk *a, int pv, int size)
{
	int	i;

	i = 0;
	while (a && i <= size / 2)
	{
		if (a->rank < pv)
			return (a);
		a = a->next;
		i++;
	}
	return (NULL);
}

t_stk	*get_btm_in_chunk(t_stk *a, int pv, int size)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->rank < pv && i > size / 2)
			return (a);
		a = a->next;
		i++;
	}
	return (NULL);
}

void	push_from_top(t_vars *vars)
{
	while (vars->a)
	{
		exec_ra(&vars->a);
		if (vars->a->rank <= vars->pv)
		{
			exec_pb(&vars->a, &vars->b);
			vars->b_len++;
			vars->a_len--;
			return ;
		}
	}
}

void	push_from_btm(t_vars *vars)
{
	while (vars->a)
	{
		exec_rra(&vars->a);
		if (vars->a->rank <= vars->pv)
		{
			exec_pb(&vars->a, &vars->b);
			vars->b_len++;
			vars->a_len--;
			return ;
		}
	}
}

void    chunk_algo2(t_vars *vars)
{
	t_stk   *top;
	t_stk   *btm;
	int		i;
	int		pv;

	i = 1;
	plen_vars(vars);
	printf("nbr of chunks : %d\n", vars->shunks_nm);
	printf("pivot : %d\n", vars->pv);
	print_list(vars->a);
	top = get_top_in_chunk(vars->a, vars->pv, vars->a_len);
	btm = get_btm_in_chunk(vars->a, vars->pivot, vars->a_len);
	printf("top : %d\n", top->data);
	printf("btm : %d\n", btm->data);
	pv = vars->pv;
	while (vars->a)
	{
		top = get_top_in_chunk(vars->a, vars->pv, vars->a_len);
		btm = get_btm_in_chunk(vars->a, vars->pivot, vars->a_len);
		if (btm && vars->fixe_len - vars->a_len <= top->pos)
			push_from_btm(vars);
		else if (top && vars->fixe_len - vars->a_len > top->pos)
			push_from_top(vars);
		else if (!btm && top)
			push_from_top(vars);
		else
			push_from_top(vars);
		i++;
		if (i == vars->pv)
			vars->pv += pv;
	}
	print_list(vars->b);
}