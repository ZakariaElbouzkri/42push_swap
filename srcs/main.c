/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:54:33 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/23 19:53:22 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main()
{
    char *line;
    int i = 0;
    while (i < 3)
    {
        
        line  = get_next_line(0);
        printf("%d", strcmp("ra\n", line));
        if (ft_strcmp("ra\n", line) == 0)
            ft_putstr(line);
        else
        {
            ft_putstr("error"); 
            exit(0);
        }
        i++;
    }
    ft_putstr("ok\n");
}