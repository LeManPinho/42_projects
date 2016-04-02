/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:56:10 by hjacque           #+#    #+#             */
/*   Updated: 2016/03/19 19:10:23 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sortlist(t_ls **begin, int (*sort)(void *, void *))
{
	t_ls	*a;
	int		i;

	i = 1;
	while (i != 0)
	{
		i = 0;
		a = *begin;
		while (a != NULL && a->next)
		{
			if (sort(a->data, a->next->data) > 0)
			{
				swap(a, begin);
				i++;
			}
			else
				a = a->next;
		}
	}
}

void	swap(t_ls *a, t_ls **begin)
{
	t_ls	*i;

	if (a == *begin)
	{
		i = a->next;
		a->next = i->next;
		i->next = a;
		*begin = i;
		return ;
	}
	i = *begin;
	while (i->next != a)
		i = i->next;
	i->next = a->next;
	i = a->next;
	a->next = i->next;
	i->next = a;
}
