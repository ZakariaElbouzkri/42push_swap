/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:12:20 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/08 18:45:58 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;

	s_len = ft_strlen(src);
	if (!dstsize)
		return (s_len);
	while (*src && --dstsize)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (s_len);
}
