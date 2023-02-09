/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:57:31 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 20:53:34 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	_ra_(t_stk **stk)
{
	int	data;
	int	pos;
	int	rank;

	if (!stk || !*stk)
		return ;
	data = (*stk)->data;
	pos = (*stk)->pos;
	rank = (*stk)->rank;
	del_first(stk);
	push_back(stk, ft_new(data, pos, rank));
	renew_indx(*stk);
}

void	_rra_(t_stk **stk)
{
	t_stk	*last;
	int		data;
	int		pos;
	int		rank;

	if (!stk || !*stk)
		return ;
	last = ft_last(*stk);
	data = last->data;
	pos = last->pos;
	rank = last->rank;
	del_last(stk);
	push_front(stk, ft_new(data, pos, rank));
	renew_indx(*stk);
}

void	_pa_(t_stk **a, t_stk **b)
{
	int	data;
	int	pos;
	int	rank;

	if (!a || !*a)
		return ;
	data = (*a)->data;
	rank = (*a)->rank;
	pos = 0;
	del_first(a);
	push_front(b, ft_new(data, pos, rank));
	renew_indx(*a);
	renew_indx(*b);
}
