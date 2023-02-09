/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:47:56 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 20:53:57 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_stk	*ft_new(int num, int pos, int rank)
{
	t_stk	*new;

	new = malloc(sizeof(t_stk));
	if (!new)
		return (NULL);
	new->data = num;
	new->pos = pos;
	new->rank = rank;
	new->next = NULL;
	return (new);
}

t_stk	*ft_last(t_stk *a)
{
	while (a->next)
		a = a->next;
	return (a);
}

int	stk_size(t_stk *a)
{
	int	len;

	len = 0;
	while (a)
	{
		a = a->next;
		len++;
	}
	return (len);
}

void	push_back(t_stk **stk, t_stk *new)
{
	t_stk	*tmp;

	if (stk)
	{
		if (!(*stk))
		{
			*stk = new;
			(*stk)->next = NULL;
			return ;
		}
		tmp = ft_last(*stk);
		tmp->next = new;
		new->next = NULL;
	}
}

void	push_front(t_stk **stk, t_stk *new)
{
	if (stk && new)
	{
		new->next = *stk;
		(*stk) = new;
	}
}
