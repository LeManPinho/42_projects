/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:54:12 by apinho            #+#    #+#             */
/*   Updated: 2016/10/06 14:49:18 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

t_dlst		*dlst_delelem(t_dlst *dlst, char *elemdel, t_tout *tout)
{
	t_double	*tmp;

	tmp = dlst->head;
	if (dlst)
		while (tmp)
		{
			tout->unset = get_to_unset(tmp->s, tout->unset);
			if (ft_strncmp(tout->unset, elemdel, ft_strlen(tout->unset)) == 0)
			{
				free(tout->unset);
				if (!tmp->next && !tmp->prev)
					ft_strdel(&dlst->head->s);
				else
					maj_dlst(dlst, tmp);
				dlst->lenght--;
				break ;
			}
			free(tout->unset);
			tmp = tmp->next;
		}
	free(tmp);
	return (dlst);
}

void		maj_dlst(t_dlst *dlst, t_double *elem)
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
}
