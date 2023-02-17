/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:01:46 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/17 12:23:58 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	checker(char **av)
{
	t_utils	vars;

	init_utils_struct(&vars);
	vars.a = parse_stack(av);
	if (!vars.a)
		ft_puterror("ERROR\n");
	vars.size_a = stk_size(vars.a);
	vars.op = get_next_line(0);
	while (vars.op)
	{
		exec_instraction(&vars);
		free(vars.op);
		vars.op = NULL;
		vars.op = get_next_line(0);
	}
	if (!stack_sorted(vars.a) || vars.b > 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	clear_stk(&vars.a);
	clear_stk(&vars.b);
}
