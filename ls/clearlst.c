/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:41:34 by hjacque           #+#    #+#             */
/*   Updated: 2016/03/19 18:32:57 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	clearlst(t_ls *begin)
{
	t_ls	*i;
	t_ls	*next;

	i = begin;
	while (i)
	{
		next = i->next;
		free(i);
		i = next;
	}
}

void	freeinfo(t_info *ret)
{
	free(ret->grp);
	free(ret->pwd);
	free(ret->rights);
	free(ret);
}
