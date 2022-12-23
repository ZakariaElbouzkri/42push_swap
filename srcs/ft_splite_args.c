/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splite_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:53:33 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 20:07:30 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    free_allocated_args(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

char    **ft_splite_args(int ac, char **av)
{
    char **arr;
    int i;

    i = 0;
    arr = malloc(sizeof(char *) * ac);
    if (!arr)
        ft_puterror("Erorr, Unable to allocate memory");
    if (ac == 2)
        return (ft_split(av[0], ' '));
    else if (ac > 2)
    {
        while (av[i])
        {
            arr[i] = ft_strdup(av[i]);
            ac--;
            i++;
        }
        arr[i] = NULL;
    }
    return (arr);
}
