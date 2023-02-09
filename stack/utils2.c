/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:03:06 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/08 23:04:32 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	del_last(t_stk **stk)
{
	t_stk	*last;
	t_stk	*tmp;

	if (stk && *stk)
	{
		if (!(*stk)->next)
		{
			free(*stk);
			*stk = NULL;
			return ;
		}
		tmp = (*stk);
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		free(last);
		tmp->next = NULL;
	}	
}

void	del_first(t_stk	**stk)
{
	t_stk	*tmp;

	if (stk && *stk)
	{
		tmp = (*stk)->next;
		free(*stk);
		*stk = NULL;
		(*stk) = tmp;
	}
}

void	clear_stk(t_stk **stk)
{
	t_stk	*tmp;

	while (*stk)
	{
		tmp = (*stk)->next;
		free(*stk);
		*stk = tmp;
	}
	*stk = NULL;
}

void	renew_indx(t_stk *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a->pos = i++;
		a = a->next;
	}
}
