/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:23:16 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 20:31:15 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	exec_operation(t_stk **a, t_stk **b, char *op)
{
	if (!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "ss\n"))
		_sa_(*a);
	else if (!ft_strcmp(op, "sb\n") || !ft_strcmp(op, "ss\n"))
		_sa_(*b);
	else if (!ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rr\n"))
		_ra_(a);
	else if (!ft_strcmp(op, "rb\n") || !ft_strcmp(op, "rr\n"))
		_ra_(b);
	else if (!ft_strcmp(op, "rra\n") || !ft_strcmp(op, "rrr\n"))
		_rra_(a);
	else if (!ft_strcmp(op, "rrb\n") || !ft_strcmp(op, "rrr\n"))
		_rra_(b);
	else if (!ft_strcmp(op, "pa\n"))
		_pa_(b, a);
	else if (!ft_strcmp(op, "pb\n"))
		_pa_(a, b);
	else
		ft_puterror("Erorr.");
}
