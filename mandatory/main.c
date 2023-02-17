/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:22:03 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/17 01:25:12 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stk	*stk;

	if (ac >= 2)
	{
		stk = parse_stack(&av[1]);
		if (!stk)
			ft_puterror("ERROR\n");
		push_swap(stk);
	}
	return (0);
}
