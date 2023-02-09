/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:51:06 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 23:23:45 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	check_args(char **args)
{
	int	triger;

	triger = 1;
	if (!check_dup(args))
		triger = 0;
	if (!check_nums(args))
		triger = 0;
	if (!triger)
	{
		free_args(args);
		ft_puterror("Erorr.");
	}
}

t_stk	*parse_stack(char **av)
{
	char	**args;
	t_stk	*stk;

	args = split_args(av);
	if (!args)
		ft_puterror("Erorr.");
	check_args(args);
	stk = args_to_stk(av);
	if (!stk)
	{
		free_args(args);
		return (NULL);
	}
	free_args(args);
	return (stk);
}
