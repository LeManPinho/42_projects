/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maj_dlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:54:12 by hjacque           #+#    #+#             */
/*   Updated: 2016/05/03 15:08:54 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			maj_dlst(t_dlst *dlst, t_double *elem)
{
	if (!elem->next && elem->prev)
	{
		dlst->tail = elem->prev;
		dlst->tail->next = NULL;
		ft_strdel(&elem->s);
	}
	else if (!elem->prev && elem->next)
	{
		dlst->head = elem->next;
		dlst->head->prev = NULL;
		ft_strdel(&elem->s);
	}
	else
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
		ft_strdel(&elem->s);
	}
	dlst->lenght--;
	return (1);
}
