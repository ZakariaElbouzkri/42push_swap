/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 04:41:14 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 19:54:04 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void    push_swap(t_cntr **cntr)
{
    check_dup((*cntr)->splited);
    check_error((*cntr)->splited);
    (*cntr)->a = ft_intit_stack((*cntr)->splited);
    free_allocated_args((*cntr)->splited);
    if (check_is_sorted((*cntr)->a))
        exit(0);
    sort_stack(&((*cntr)->a), &((*cntr)->b));
}

int main(int ac, char **av)
{
    t_cntr *container;
    if (ac < 2)
        ft_puterror("Wrong number of args");
    else 
    {
        container = ft_init_cntr(ac, av);
        push_swap(&container);
        t_stk *a, *b;

        a = container->a;
        b = container->b;
        while (a)
        {
            printf("%d\n", a->num);
            a = a->next;
        }
        ft_putendl_fd("stack b:", 1);
        while (b)
        {
            printf("%d\n", b->num);
            b = b->next;
        }
    }
}

