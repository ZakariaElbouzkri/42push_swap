/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:41:22 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/17 12:25:09 by zel-bouz         ###   ########.fr       */
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
