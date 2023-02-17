/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:23:16 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/17 12:26:07 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	clear_and_exit(t_utils *vars)
{
	if (vars->op)
		free(vars->op);
	clear_stk(&vars->a);
	clear_stk(&vars->b);
	ft_puterror("ERROR\n");
}

void	exec_instraction(t_utils *vars)
{
	if (!ft_strcmp(vars->op, "sa\n") || !ft_strcmp(vars->op, "sb\n")
		|| !ft_strcmp(vars->op, "ss\n"))
		swap_stack(vars);
	else if (!ft_strcmp(vars->op, "ra\n") || !ft_strcmp(vars->op, "rb\n")
		|| !ft_strcmp(vars->op, "rr\n"))
		rotate_stack(vars);
	else if (!ft_strcmp(vars->op, "rra\n") || !ft_strcmp(vars->op, "rrb\n")
		|| !ft_strcmp(vars->op, "rrr\n"))
		reverse_rotete_stack(vars);
	else if (!ft_strcmp(vars->op, "pb\n")
		||!ft_strcmp(vars->op, "pa\n"))
		push_to_stack(vars);
	else
		clear_and_exit(vars);
}
