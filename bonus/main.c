/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:28:29 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/16 05:02:36 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int main(int ac, char **av)
{
	t_stk	*stk;

	if (ac >= 2)
	{
		stk = parse_stack(&av[1]);
		if (!stk)
			ft_puterror("ERROR\n");		
	}
	return (0);
}
