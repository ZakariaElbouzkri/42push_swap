/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:10:06 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/14 07:50:33 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	exec_sa(t_stk *a)
{
	_sa_(a);
	ft_putstr("sa\n");
}

void	exec_sb(t_stk *b)
{
	_sa_(b);
	ft_putstr("sb\n");
}

void	exec_ss(t_stk *a, t_stk *b)
{
	_ss_(a, b);
	ft_putstr("ss\n");
}

void	exec_ra(t_stk **a)
{
	_ra_(a);
	ft_putstr("ra\n");
}

void	exec_rb(t_stk **b)
{
	_ra_(b);
	ft_putstr("rb\n");
}
