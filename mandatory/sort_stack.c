/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:36:35 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/17 12:21:06 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_nbr_chunks(int len)
{
	if (len < 40)
		return (len / 2);
	else if (len < 499)
		return (len / 20);
	else
		return (len / 55);
}

void	fill_vars(t_vars *vars)
{
	vars->a_len = stk_size(vars->a);
	vars->b_len = stk_size(vars->b);
	vars->a_min = min_element(vars->a);
	vars->b_min = min_element(vars->b);
	vars->a_max = max_element(vars->a);
	vars->b_max = max_element(vars->b);
	vars->fixe_len = vars->a_len;
}

void	sort_stack(t_vars *vars)
{
	fill_vars(vars);
	if (!stack_sorted(vars->a))
	{
		if (vars->a_len <= 5)
			sort_small(vars);
		else
		{
			vars->shunks_nm = get_nbr_chunks(vars->a_len);
			vars->pivot = vars->a_len / vars->shunks_nm;
			chunk_algo(vars);
		}
	}
}
