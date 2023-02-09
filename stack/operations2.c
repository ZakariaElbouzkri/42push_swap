/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:59:17 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 20:53:42 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	_sa_(t_stk *stk)
{
	if (!stk)
		return ;
	ft_swap(&stk->data, &stk->next->data);
	ft_swap(&stk->rank, &stk->next->rank);
	ft_swap(&stk->pos, &stk->next->pos);
	renew_indx(stk);
}

void	_ss_(t_stk *a, t_stk *b)
{
	_sa_(a);
	_sa_(b);
}

void	_rr_(t_stk **a, t_stk **b)
{
	_ra_(a);
	_ra_(b);
}

void	_rrr_(t_stk **a, t_stk **b)
{
	_rra_(a);
	_rra_(b);
}

void	exec_pb(t_stk **a, t_stk **b)
{
	_pa_(a, b);
	ft_putstr("pb\n");
}
