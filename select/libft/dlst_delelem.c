/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_delelem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:54:12 by hjacque           #+#    #+#             */
/*   Updated: 2016/05/03 15:08:54 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst		*dlst_delelem(t_dlst *dlst, char *elemdel)
{
	t_double	*tmp;
	int			i;

	tmp = dlst->head;
	i = 0;
	if (dlst)
		while (tmp && !i)
		{
			if (ft_strncmp(tmp->s, elemdel, ft_strlen(elemdel)) == 0)
			{
				if (!tmp->next && !tmp->prev)
				{
					ft_strdel(&dlst->head->s);
					free(dlst);
				}
				else
					i = maj_dlst(dlst, tmp);
				dlst->lenght--;
				free(tmp);
			}
			tmp = tmp->next;
		}
	return (dlst);
}
