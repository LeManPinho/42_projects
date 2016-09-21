/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:55:49 by hjacque           #+#    #+#             */
/*   Updated: 2016/01/25 13:03:05 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nextlist;

	if (!alst || !*alst)
		return ;
	lst = (*alst);
	nextlist = (*alst)->next;
	ft_lstdelone(&lst, del);
	if (nextlist)
		ft_lstdel(&nextlist, del);
	*alst = NULL;
}
