/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/06/27 14:48:47 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	get_longest_word(t_tout *tout)
{
	int	i;
	int	current_size;
	int	max_size;

	i = 0;
	current_size = 0;
	max_size = 0;
	while (i < tout->word_count)
	{
		current_size = ft_strlen((char *)tout->words[i]);
		if (current_size > max_size)
			max_size = current_size;
		i++;
	}
	return (max_size);
}
