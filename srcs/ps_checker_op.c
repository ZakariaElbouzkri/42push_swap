/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:34:33 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 20:04:05 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	_sa_(t_stk **a)
{
	int i;

	i = (*a)->next->num;
	(*a)->next->num = (*a)->num;
	(*a)->num = i;
}

void	_ss_(t_stk **a, t_stk **b)
{
	_sa_(a);
	_sa_(b);
}

void	_ra_(t_stk **a)
{
	t_stk *top;

	ft_add_back(a, ft_new((*a)->num));
	top = (*a);	
	(*a) = (*a)->next;
	free(top);
	top = NULL;
}

void	_rr_(t_stk **a, t_stk **b)
{
	_ra_(a);
	_ra_(b);
}

void	_pa_(t_stk **a, t_stk **b)
{
	int i;
	t_stk *top;

	i = (*a)->num;
	ft_add_front(b, ft_new(i));
	top = (*a);	
	(*a) = (*a)->next;
	free(top);
	top = NULL;
	
}

void	_rra_(t_stk **a)
{
	t_stk *btm;

	btm = ft_last(*a);
	ft_add_front(a, ft_new(btm->num));
	ft_del_last(a);
}

void	_rrr_(t_stk **a, t_stk **b)
{
	_rra_(a);
	_rra_(b);
}
