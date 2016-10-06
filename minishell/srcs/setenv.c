/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:16:16 by apinho            #+#    #+#             */
/*   Updated: 2016/10/06 15:12:31 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	setenvnow(t_tout *tout)
{
	if (tout->lines[1] != NULL)
		setit(tout->env, tout->lines[1],\
			ft_strjoinchar(tout->lines[1], tout->lines[2], '='));
	else
		printenv(tout);
}

void	unsetenvnow(t_tout *tout)
{
	dlst_delelem(tout->env, tout->lines[1], tout);
}

t_dlst	*setit(t_dlst *dlst, char *elem, char *modifelem)
{
	t_double *tmp;

	tmp = dlst->head;
	if (dlst)
	{
		while (tmp)
		{
			if (ft_strncmp(tmp->s, elem, ft_strlen(elem)) == 0)
			{
				ft_strdel(&tmp->s);
				tmp->s = ft_strdupfree(modifelem);
				return (dlst);
			}
			tmp = tmp->next;
		}
		dlst_addbackw(dlst, dlst_allelem(modifelem));
		free(modifelem);
	}
	return (dlst);
}

void	printenv(t_tout *tout)
{
	t_double	*gogo;

	gogo = tout->env->head;
	if (gogo)
	{
		while (gogo)
		{
			ft_putendl(gogo->s);
			gogo = gogo->next;
		}
	}
}
