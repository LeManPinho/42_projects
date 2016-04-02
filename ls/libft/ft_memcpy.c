/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:59:33 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 01:59:34 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		x;
	char		*dst2;
	const char	*src2;

	x = 0;
	dst2 = dst;
	src2 = src;
	while (x < n)
	{
		dst2[x] = src2[x];
		x++;
	}
	return (dst2);
}
