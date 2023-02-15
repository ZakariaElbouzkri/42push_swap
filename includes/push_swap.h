/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:52:06 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/15 03:34:24 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

typedef struct s_vars
{
	t_stk	*a;
	t_stk	*b;
	int		a_min;
	int		b_min;
	int		a_max;
	int		b_max;
	int		pivot;
	int		a_len;
	int		b_len;
	int		fixe_len;
	int		shunks_nm;
	int		pv;
}	t_vars;

void	push_swap(t_stk *a);
void	sort_stack(t_vars *vars);
void	init_vars(t_vars *vars);

// sort functions:

void	sort_small(t_vars *vars);
void	sort_five(t_vars *vars);
void	sort_three(t_vars *vars);
void	chunk_algo(t_vars *vars);
void	rotate_b(t_vars *vars);
int		closest_nbr_of_chunk(t_vars *vars);

// utils:
void	rotate_b(t_vars *vars);
int		calc_moves(int pos1, int pos2, int len);
void	push_min(t_vars *vars);
void	push_closest_nbr(t_vars *vars, int pos);
int		max_element(t_stk *a);
int		min_element(t_stk *a);
t_stk	*max_elem_node(t_stk *stk);
t_stk	*min_elem_node(t_stk *stk);
t_stk	*uninitialized_max(t_stk *stk);
void	fill_vars(t_vars *vars);
void	init_final_pos(t_stk *stk);
void	print_list(t_stk *stk);
void	push_max_to_b(t_vars *vars);
void	push_elem(t_vars *vars, t_stk *node, int size);
void	push_max_to_b(t_vars *vars);
t_stk	*under_max_node(t_stk *stk, t_stk *mx);

#endif
