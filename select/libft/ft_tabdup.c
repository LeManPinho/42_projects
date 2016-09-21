/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:33:31 by apinho            #+#    #+#             */
/*   Updated: 2016/09/20 16:27:15 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	**ft_tabdup(char **tab)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char**)malloc(sizeof(char*) * ft_tablen(tab) + 1);
	while (tab && tab[i])
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
