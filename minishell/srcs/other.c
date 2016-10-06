/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:08:46 by apinho            #+#    #+#             */
/*   Updated: 2016/10/06 17:29:31 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_to_unset(char *varenv, char *to_unset)
{
	size_t		i;

	i = 0;
	while (varenv[i])
	{
		if (varenv[i] == '=')
			break ;
		i++;
	}
	to_unset = malloc(sizeof(char) * (i + 1));
	to_unset = ft_strncpy(to_unset, varenv, i);
	to_unset[i] = '\0';
	return (to_unset);
}

void	mainstuff(t_tout *tout)
{
	tout->epured = epur_str(ft_strdup(tout->line));
	if (count_words(tout->epured) > 1)
		tout->lines = ft_strsplit(tout->epured, ' ');
	else
	{
		tout->lines = malloc(sizeof(char *) * 3);
		tout->lines[0] = ft_strdup(tout->epured);
		tout->lines[1] = NULL;
		tout->lines[2] = NULL;
	}
	tout->cmd = ft_strdup(tout->lines[0]);
}

void	freeall(t_tout *tout)
{
	free(tout->cmd);
	free(tout->epured);
	free_tab(tout->lines);
}

void	freeall2(t_tout *tout)
{
	free(tout->line);
	freedlst(tout->env);
	free(tout);
}

void	freedlst(t_dlst *dlst)
{
	t_double	*tmp;
	t_double	*tmp2;

	tmp = dlst->head;
	if (dlst)
		while (tmp)
		{
			if (!tmp->next && !tmp->prev)
				ft_strdel(&dlst->head->s);
			else
				maj_dlst(dlst, tmp);
			dlst->lenght--;
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
	free(tmp);
	free(dlst);
}
