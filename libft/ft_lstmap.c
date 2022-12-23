/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:19:58 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/11/21 02:42:02 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p1;
	t_list	*p2;

	if (!lst || !f || !del)
		return (NULL);
	p2 = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		p1 = ft_lstnew(f(lst->content));
		if (!p1)
		{
			ft_lstclear(&p2, del);
			return (NULL);
		}
		ft_lstadd_back(&p2, p1);
		lst = lst->next;
		p1 = NULL;
	}
	return (p2);
}
