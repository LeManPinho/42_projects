/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tout.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/09/20 18:05:33 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_tout	*inittout(int ac, char **av)
{
	int		i;
	t_tout	*tout;

	i = 0;
	if (!(tout = (t_tout*)malloc(sizeof(t_tout))))
		return (NULL);
	tout->word_count = ac - 1;
	tout->words = av + 1;
	tout->single_column_width = get_longest_word(tout) + 3;
	tout->white = (int*)malloc((ac - 1) * sizeof(int));
	ft_bzero(tout->white, (ac - 1) * sizeof(int));
	tout->word_cursor = 0;
	return (tout);
}

t_tout	*reset_tout(t_tout *new_tout)
{
	static	t_tout	*fresh_tout = NULL;

	if (new_tout)
		fresh_tout = new_tout;
	return (fresh_tout);
}
