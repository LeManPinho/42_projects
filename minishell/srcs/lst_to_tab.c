/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:20:50 by apinho            #+#    #+#             */
/*   Updated: 2016/10/06 17:29:03 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**lst_to_tab(t_tout *tout)
{
	t_double	*gogo;
	char		**tab;
	int			i;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * (tout->env->lenght + 1));
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

int		count_words(char *str)
{
	int		i;
	int		words;

	words = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			words++;
		i++;
	}
	return (words);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
