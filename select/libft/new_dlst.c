/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:54:12 by hjacque           #+#    #+#             */
/*   Updated: 2016/05/03 15:08:54 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst		*new_dlst(void)
{
	t_dlst *new;

	new = (t_dlst*)malloc(sizeof(t_dlst));
	if (new != NULL)
	{
		new->head = NULL;
		new->tail = NULL;
		new->lenght = 0;
	}
	return (new);
}
