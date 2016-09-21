/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_addbackw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:54:12 by hjacque           #+#    #+#             */
/*   Updated: 2016/05/03 15:08:54 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst		*dlst_addbackw(t_dlst *dlst, t_double *dble)
{
	if (dlst && dble)
	{
		if (dlst->tail == NULL)
		{
			dlst->head = dble;
			dlst->tail = dble;
		}
		else
		{
			dlst->tail->next = dble;
			dble->prev = dlst->tail;
			dlst->tail = dble;
		}
		dlst->lenght++;
	}
	return (dlst);
}
