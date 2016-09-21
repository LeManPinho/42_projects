/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:33:31 by apinho            #+#    #+#             */
/*   Updated: 2016/09/20 17:48:30 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_from_array(int nth, void *array, size_t width, int length)
{
	char	*to_remove;

	to_remove = (((char*)array) + nth * width);
	ft_memmove((void*)to_remove, (void*)(to_remove + width)
		, (length - nth - 1) * width);
}
