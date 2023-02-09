/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:10:38 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 23:34:06 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	check_dup(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	str_is_digit(char *s)
{
	int	plus;
	int	minus;

	plus = 1;
	minus = 1;
	if (!ft_strcmp(s, "-") || !ft_strcmp(s, "-"))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
		{
			if (*s == '+' && plus != 0)
				plus = 0;
			if (*s == '-' && minus != 0)
				minus = 0;
			else if ((*s == '+' && !plus) || (*s == '-' && !minus))
				return (0);
		}
		s++;
	}
	return (1);
}

int	check_nums(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!str_is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}
