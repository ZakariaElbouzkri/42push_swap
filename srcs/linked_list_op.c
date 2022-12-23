/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:48:52 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 19:53:05 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stk	*ft_new(int data)
{
	t_stk *new;

	new = malloc(sizeof(t_stk));
	if (!new)
		ft_puterror("Unable to allocate memory");
	new->next = NULL;
	new->prev = NULL;
	new->num = data;
	return (new);
}

t_stk	*ft_first(t_stk *a)
{
	while (a->prev)
		a = a->prev;
	return (a);
}

t_stk	*ft_last(t_stk *a)
{
	while (a->next)
	{
		a = a->next;
	}
	return (a);
}

int	ft_stack_size(t_stk *a)
{
	int len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

void	ft_add_back(t_stk **stk, t_stk *new)
{
	t_stk *tmp;

	if (!stk)
		return ;
	if (!*stk)
	{
		(*stk) = new;
		(*stk)->next = NULL;
		(*stk)->prev = NULL;
		return ;
	}
	tmp = ft_last(*stk);
	tmp->next = new;
	new->prev = tmp;
}

void	ft_add_front(t_stk **a, t_stk *new)
{
	if (a)
	{
		if (!*a)
		{
			(*a) = new;
		}
		else 
		{
			new->next = (*a);
			(*a)->prev = new;
			(*a) = new;
		}
	}
}

void	ft_del_last(t_stk **a)
{
	t_stk *top;

	top = (*a);
	while ((*a)->next->next)
		(*a) = (*a)->next;
	top = (*a)->next;
	free(top);
	(*a)->next = NULL;
	(*a) = ft_first(*a);
}
