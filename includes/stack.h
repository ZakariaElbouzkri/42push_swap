/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:46:22 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 20:58:28 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_stk
{
	int				data;
	int				pos;
	int				rank;
	struct s_stk	*next;
}	t_stk;

// stack operations:

void	_ra_(t_stk **stk);
void	_rra_(t_stk **stk);
void	_pa_(t_stk **a, t_stk **b);
void	_sa_(t_stk *stk);
void	_ss_(t_stk *a, t_stk *b);
void	_rr_(t_stk **a, t_stk **b);
void	_rrr_(t_stk **a, t_stk **b);
void	exec_pb(t_stk **a, t_stk **b);

// stack funs helps to print op:

void	exec_sa(t_stk *a);
void	exec_sb(t_stk *b);
void	exec_ss(t_stk *a, t_stk *b);
void	exec_ra(t_stk **a);
void	exec_rb(t_stk **b);
void	exec_rr(t_stk **a, t_stk **b);
void	exec_rra(t_stk **a);
void	exec_rrb(t_stk **b);
void	exec_rrr(t_stk **a, t_stk **b);
void	exec_pa(t_stk **b, t_stk **a);

// stack utils:

int		stack_sorted(t_stk *a);
t_stk	*ft_new(int num, int pos, int rank);
t_stk	*ft_last(t_stk *a);
int		stk_size(t_stk *a);
void	push_back(t_stk **stk, t_stk *new);
void	push_front(t_stk **stk, t_stk *new);
void	del_last(t_stk **stk);
void	del_first(t_stk	**stk);
void	clear_stk(t_stk **stk);
void	renew_indx(t_stk *a);

#endif
