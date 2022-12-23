/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:10:00 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 20:08:16 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_stack(t_stk **a, t_stk **b)
{
	int a_len;

	a_len = ft_stack_size((*a));
	if (a_len <= 5)
		sort_small(a, b);
	else 
		sort_big(a, b, a_len);
}
