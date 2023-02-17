/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:28:08 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/17 11:28:00 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	stack_sorted(t_stk *a)
{
	int	i;
	int	j;
	int	triger;

	triger = 1;
	if (!a)
		return (0);
	if (!a->next)
		return (1);
	while (a->next)
	{
		i = a->data;
		j = a->next->data;
		if (i > j)
			triger = 0;
		a = a->next;
	}
	return (triger);
}

void	print_list(t_stk *stk)
{
	int	i;

	i = 0;
	if (!stk)
		return ;
	while (stk)
	{
		ft_printf("value : %d\t| final pos : %d\t| pos : %d\n",
			stk->data, stk->rank, stk->pos);
		stk = stk->next;
		i++;
	}
}
