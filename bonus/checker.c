/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:28:29 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 20:46:03 by zel-bouz         ###   ########.fr       */
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
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	if (b)
		clear_stk(&b);
	clear_stk(&a);
}
