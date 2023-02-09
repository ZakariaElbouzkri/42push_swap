/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:41:51 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/08 18:45:32 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len += write(1, "(null)", 6));
	while (*s)
		len += ft_putchar(*s++);
	return (len);
}
