/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:37:56 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 20:55:40 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "stack.h"
# include "push_swap.h"
# include "checker.h"

t_stk	*parse_stack(char **av);
char	**split_args(char **arr);
int		check_dup(char **av);
void	free_args(char **arr);
int		check_nums(char **av);
t_stk	*args_to_stk(char **args);

#endif