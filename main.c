/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:01:13 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 21:04:29 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"
#include "includes/checker.h"
#include "includes/push_swap.h"


void	exec_programe(char	**av, char *pro)
{
	t_stk	*stk;

	stk = parse_stack(av);
	if (!stk)
		ft_puterror("Erorr");
	if (!strcmp(pro, "./checker"))
		checker(stk);
	else
		push_swap(stk);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		exec_programe(&av[1], av[0]);
}