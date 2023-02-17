/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:29:43 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/17 10:53:56 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"
# include "libft.h"
# include "parser.h"

typedef struct s_utils
{
	int     size_a;
	int     size_b;
	t_stk   *a;
	t_stk   *b;
    char    *op;
}   t_utils;

void	checker(char **av);
void	exec_operation(t_stk **a, t_stk **b, char *op);

#endif
