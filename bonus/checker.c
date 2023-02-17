/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:01:46 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/17 11:30:58 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	init_utils_struct(t_utils *vars)
{
	vars->a = NULL;
	vars->b = NULL;
	vars->size_a = 0;
	vars->size_b = 0;
	vars->op = NULL;
}

void	swap_stack(t_utils	*vr)
{
	if (!ft_strcmp("sa\n", vr->op))
		_sa_(vr->a);
	else if (!ft_strcmp("sb\b", vr->op))
		_sa_(vr->b);
	else
	{
		_sa_(vr->a);
		_sa_(vr->b);
	}
}

void	rotate_stack(t_utils *vr)
{
	if (!ft_strcmp(vr->op, "ra\n"))
		_ra_(&vr->a);
	else if (!ft_strcmp(vr->op, "rb\n"))
		_ra_(&vr->b);
	else
	{
		_ra_(&vr->b);
		_ra_(&vr->a);
	}
}

void	reverse_rotete_stack(t_utils *vr)
{
	if (!ft_strcmp(vr->op, "rra\n"))
		_rra_(&vr->a);
	else if (!ft_strcmp(vr->op, "rrb\n"))
		_rra_(&vr->b);
	else
	{
		_rra_(&vr->a);
		_rra_(&vr->b);	
	}
}

void	push_to_stack(t_utils *vr)
{
	if (!ft_strcmp(vr->op, "pa\n"))
	{
		if (vr->size_b > 0)
		{
			_pa_(&vr->b, &vr->a);
			vr->size_b--;
			vr->size_a++;
		}
	}
	else if (!ft_strcmp(vr->op, "pb\n"))
	{
		if (vr->size_a > 0)
		{
			_pa_(&vr->a, &vr->b);
			vr->size_a--;
			vr->size_b++;
		}
	}
}

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
	if (!ft_strcmp(vars->op, "sa\n") || !ft_strcmp(vars->op, "sb\n") || !ft_strcmp(vars->op, "ss\n"))
		swap_stack(vars);
	else if (!ft_strcmp(vars->op, "ra\n") || !ft_strcmp(vars->op, "rb\n") || !ft_strcmp(vars->op, "rr\n"))
		rotate_stack(vars);
	else if (!ft_strcmp(vars->op, "rra\n") || !ft_strcmp(vars->op, "rrb\n") || !ft_strcmp(vars->op, "rrr\n"))
		reverse_rotete_stack(vars);
	else if (!ft_strcmp(vars->op, "pb\n") || !ft_strcmp(vars->op, "pa\n"))
		push_to_stack(vars);
	else
		clear_and_exit(vars);
}

void	checker(char **av)
{
	t_utils	vars;

	init_utils_struct(&vars);
	vars.a = parse_stack(av);
	if (!vars.a)
		ft_puterror("ERROR\n");
	vars.size_a = stk_size(vars.a);
	vars.op = get_next_line(0);
	while (vars.op)
	{
		exec_instraction(&vars);
		free(vars.op);
		vars.op = NULL;
		vars.op = get_next_line(0);
	}
	if (!stack_sorted(vars.a) || vars.b > 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	clear_stk(&vars.a);
	clear_stk(&vars.b);
}
