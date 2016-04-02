/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:41:14 by hjacque           #+#    #+#             */
/*   Updated: 2016/03/19 18:31:50 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*addelem(t_ls **begin, void *data)
{
	t_ls	*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->data = data;
	ret->next = *begin;
	*begin = ret;
	return (ret);
}
