/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:54:48 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 19:52:55 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// function that inits the container:
t_cntr	*ft_init_cntr(int ac, char **av)
{
	t_cntr	*new;

	new = malloc(sizeof(t_cntr));
	if (!new)
		ft_puterror("Unable to allocate memory");
	new->av = &av[1];
	new->splited = ft_splite_args(ac, &av[1]);
	new->ac = ac;
	new->a = NULL;
	new->b = NULL;
	return (new);
}
// function that inits the stack:



t_stk	*ft_intit_stack(char **arr)
{
	int	i;
	t_stk *a;

	a = ft_new(ft_atoi(arr[0]));
	i = 1;
	while (arr[i])
	{
		ft_add_back(&a, ft_new(ft_atoi(arr[i])));
		i++;
	}
	return (a);
}
