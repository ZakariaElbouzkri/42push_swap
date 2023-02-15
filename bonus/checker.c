/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:28:29 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/14 03:39:59 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	checker(t_stk *a)
{
	t_stk	*b;
	char	*op;
	int		a_len;

	b = NULL;
	a_len = stk_size(a);
	op = get_next_line(0);
	while (op)
	{
		exec_operation(&a, &b, op);
		free(op);
		op = NULL;
		op = get_next_line(0);
	}
	if (stack_sorted(a) && a_len == stk_size(a))
	{
		clear_stk(&a);
		ft_printf("OK\n");
	}
	else
	{
		if (b)
			clear_stk(&b);
		if (a)
			clear_stk(&a);
		ft_printf("KO\n");
	}
}
