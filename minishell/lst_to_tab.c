/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:20:50 by apinho            #+#    #+#             */
/*   Updated: 2016/05/03 15:11:58 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lst_to_tab(t_tout *tout)
{
	t_double	*gogo;
	char		**tab;
	int			i;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * tout->env->lenght + 1);
	gogo = tout->env->head;
	if (gogo)
	{
		while (gogo)
		{
			tab[i] = ft_strdup(gogo->s);
			i++;
			gogo = gogo->next;
		}
	}
	tab[i] = NULL;
	return (tab);
}

void	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}
