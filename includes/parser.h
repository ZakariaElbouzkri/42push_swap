/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:37:56 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/16 04:46:06 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "stack.h"

t_stk	*parse_stack(char **av);
char	**split_args(char **arr);
int		check_dup(char **av);
void	free_args(char **arr);
int		check_nums(char **av);
t_stk	*args_to_stk(char **args);

#endif