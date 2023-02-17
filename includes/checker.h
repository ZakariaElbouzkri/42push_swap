/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:29:43 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/17 12:25:30 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"
# include "libft.h"
# include "parser.h"
# include <stdlib.h>

typedef struct s_utils
{
	int		size_a;
	int		size_b;
	t_stk	*a;
	t_stk	*b;
	char	*op;
}	t_utils;

void	checker(char **av);
void	clear_and_exit(t_utils *vars);
void	exec_instraction(t_utils *vars);
void	init_utils_struct(t_utils *vars);
void	swap_stack(t_utils	*vr);
void	rotate_stack(t_utils *vr);
void	reverse_rotete_stack(t_utils *vr);
void	push_to_stack(t_utils *vr);

#endif
