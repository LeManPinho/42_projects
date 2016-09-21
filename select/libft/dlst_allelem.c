/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_allelem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:54:12 by hjacque           #+#    #+#             */
/*   Updated: 2016/05/03 15:08:54 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_double	*dlst_allelem(char *elem)
{
	t_double *data;

	data = (t_double*)malloc(sizeof(t_double));
	if (data != NULL)
	{
		data->s = ft_strdup(elem);
		data->next = NULL;
		data->prev = NULL;
	}
	return (data);
}
