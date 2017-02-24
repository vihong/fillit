/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:10:02 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/10 10:32:50 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;

	node = NULL;
	if (lst && f)
	{
		node = f(lst);
		node->next = lst->next ? ft_lstmap(lst->next, f) : NULL;
	}
	return (node);
}
