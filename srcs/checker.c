/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:43:57 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 20:12:05 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_rr(t_stk **a, t_stk **b, char *op)
{
	if (!ft_strcmp("ra\n", op))
		_ra_(a);
	else if (!ft_strcmp("rb\n", op))
		_ra_(b);
	else if (!ft_strcmp("rr\n", op))
		_rr_(a, b);
}

void	exec_rrr(t_stk **a, t_stk **b, char *op)
{
	if (!ft_strcmp("rra\n", op))
		_rra_(a);
	else if (!ft_strcmp("rrb\n", op))
		_rra_(b);
	else if (!ft_strcmp("rrr\n", op))
		_rrr_(a, b);
}

void	exex_ss(t_stk **a, t_stk **b, char *op)
{
	if (!ft_strcmp("sa\n", op))
		_sa_(a);
	else if (!ft_strcmp("sb\n", op))
		_sa_(b);
	else if (!ft_strcmp("ss\n", op))
		_ss_(a, b);
}

void	exec_p(t_stk **a, t_stk **b, char *op)
{
	if (!ft_strcmp("pa\n", op))
		_pa_(b, a);
	else if (!ft_strcmp("pb\n", op))
		_pa_(a, b);
}

void	make_op(t_stk **a, t_stk **b, char *line)
{
	if (!ft_strcmp("ra\n", line) || !ft_strcmp("rb\n", line) || !ft_strcmp("rr\n", line))
		exec_rr(a, b, line);
	else if (!ft_strcmp("rra\n", line) || !ft_strcmp("rrb\n", line) || !ft_strcmp("rrr\n", line))
		exec_rrr(a, b, line);
	else if (!ft_strcmp("sa\n", line) || !ft_strcmp("sb\n", line) || !ft_strcmp("ss\n", line))
		exex_ss(a, b, line);
	else if (!ft_strcmp("pa\n", line) || !ft_strcmp("pb\n", line))
		exec_p(a, b, line);
	else 
		ft_puterror("Erorr.");
}

void	checker(t_stk **a, t_stk **b)
{
	char *line;
	int	a_len;

	a_len = ft_stack_size(*a);
	line = get_next_line(0);
	while (line)
	{
		make_op(a, b, line);
		if (check_is_sorted(*a) && a_len == ft_stack_size(*a))
			break;
		line = get_next_line(0);
	}
	if (!check_is_sorted(*a))
		ft_putstr("KO!");
	else
		ft_putstr("OK\n");
}

int main(int ac, char **av)
{
	t_cntr *container;

	container = NULL;
    if (ac >= 2)
    {
        container = ft_init_cntr(ac, av);
		check_dup(container->splited);
		check_error(container->splited);
		container->a = ft_intit_stack(container->splited);
		free_allocated_args(container->splited);
		if (check_is_sorted(container->a))
			exit(0);
		checker(&(container->a), &(container->b));
    }
	else 
		ft_puterror("Wrong number of args");

	t_stk *a = container->a;

	ft_putstr("stack a:\n");
	while (a)
	{
		printf("%d\n", a->num);
		a = a->next; 
	}
}