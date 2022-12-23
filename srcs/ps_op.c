/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:34:33 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 19:53:52 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa_b_op(t_stk **a, char *op)
{
	int i;

	i = (*a)->next->num;
	(*a)->next->num = (*a)->num;
	(*a)->num = i;
	ft_putstr(op);
}

void	ss_op(t_stk **a, t_stk **b)
{
	sa_b_op(a, "s");
	sa_b_op(b, "s\n");
}

void	ra_b_op(t_stk **a, char *op)
{
	t_stk *top;

	ft_add_back(a, ft_new((*a)->num));
	top = (*a);	
	(*a) = (*a)->next;
	free(top);
	top = NULL;
	ft_putstr(op);
}

void	rr_op(t_stk **a, t_stk **b)
{
	ra_b_op(a, "r");
	ra_b_op(b, "r\n");
}

void	pa_b_op(t_stk **a, t_stk **b, char *op)
{
	int i;
	t_stk *top;

	i = (*a)->num;
	ft_add_front(b, ft_new(i));
	top = (*a);	
	(*a) = (*a)->next;
	free(top);
	top = NULL;
	ft_putstr(op);
	
}

void	rra_b_op(t_stk **a, char *op)
{
	t_stk *btm;

	btm = ft_last(*a);
	ft_add_front(a, ft_new(btm->num));
	ft_del_last(a);
	ft_putstr(op);
}

void	rrr_op(t_stk **a, t_stk **b)
{
	rra_b_op(a, "r");
	rra_b_op(b, "rr\n");
}
