/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 04:39:12 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 20:07:48 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "../libft/libft.h"

typedef struct stack
{
	int num;
	struct stack *next;
	struct stack *prev;
} t_stk;

typedef struct container
{
	int ac;
	char **av;
	char **splited;
	t_stk *a;
	t_stk *b;
}	t_cntr;

// parser:
void	check_dup(char **arr);
void	check_error(char **arr);
char	**ft_splite_args(int ac, char **av);
t_cntr	*ft_init_cntr(int ac, char **av);
t_stk	*ft_intit_stack(char **arr);
void    free_allocated_args(char **arr);

// linked list operations:
t_stk	*ft_new(int data);
t_stk	*ft_last(t_stk *a);
t_stk	*ft_first(t_stk *a);
int		ft_stack_size(t_stk *a);
void	ft_add_back(t_stk **stk, t_stk *new);
void	ft_add_front(t_stk **a, t_stk *new);
void	ft_del_last(t_stk **a);
int		check_is_sorted(t_stk *a);

// sort operations :
void	sa_b_op(t_stk **a, char *op);
void	ss_op(t_stk **a, t_stk **b);
void	ra_b_op(t_stk **a, char *op);
void	rr_op(t_stk **a, t_stk **b);
void	pa_b_op(t_stk **a, t_stk **b, char *op);
void	rra_b_op(t_stk **a, char *op);
void	rrr_op(t_stk **a, t_stk **b);

// sort functions :
void	sort_stack(t_stk **a, t_stk **b);
void	sort_small(t_stk **a, t_stk **b);
void	sort_big(t_stk **a, t_stk **b, int len);
void	sort_three(t_stk **a);
void	sort_two(t_stk **a);
void	sort_four(t_stk **a, t_stk **b);
void	sort_five(t_stk **a, t_stk **b);

// utils 
void	push_min_pb(t_stk **a, t_stk **b);
int		index_of_elem(t_stk *a, int m);
int		min_element(t_stk *a);
int		max_element(t_stk *a);

// checker op:

void	_sa_(t_stk **a);
void	_ss_(t_stk **a, t_stk **b);
void	_ra_(t_stk **a);
void	_rr_(t_stk **a, t_stk **b);
void	_pa_(t_stk **a, t_stk **b);
void	_rra_(t_stk **a);
void	_rrr_(t_stk **a, t_stk **b);

#endif





// void	push_min_b(t_stk **a, t_stk **b)
// {
// 	int min;

// 	min = min_element(*a);
// 	while ((*a)->num != min)
// 	{
// 		if ((*a)->next->num != min && (*a)->next->next->num != min)
// 		{
// 			while ((*a)->num != min)
// 				rra_b_op(a, "rra\n");
// 			break;
// 		}
// 		if ((*a)->next->num == min || (*a)->next->next->num == min)
// 			ra_b_op(a, "ra\n");
// 		if ((*a)->num != min)
// 			ra_b_op(a, "ra\n");
// 	}
// 	pa_b_op(a, b, "pb\n");
// }