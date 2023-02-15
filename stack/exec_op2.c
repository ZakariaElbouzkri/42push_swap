/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:11:15 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/14 07:50:18 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	exec_rr(t_stk **a, t_stk **b)
{
	_rr_(a, b);
	ft_putstr("rr\n");
}

void	exec_rra(t_stk **a)
{
	_rra_(a);
	ft_putstr("rra\n");
}

void	exec_rrb(t_stk **b)
{
	_rra_(b);
	ft_putstr("rrb\n");
}

void	exec_rrr(t_stk **a, t_stk **b)
{
	_rrr_(a, b);
	ft_putstr("rrr\n");
}

void	exec_pa(t_stk **b, t_stk **a)
{
	_pa_(b, a);
	ft_putstr("pa\n");
}
