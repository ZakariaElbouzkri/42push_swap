/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:44:43 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 20:50:49 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_stk	*args_to_stk(char **args)
{
	t_stk	*stk;
	t_stk	*new;
	long	num;
	int		i;

	i = 0;
	stk = NULL;
	while (*args)
	{
		num = ft_atoi_long(*args);
		if (num > INT_MAX || num < INT_MIN)
			return (NULL);
		new = ft_new((int)num, i++, 0);
		if (!new)
			return (NULL);
		push_back(&stk, new);
		args++;
	}
	return (stk);
}
