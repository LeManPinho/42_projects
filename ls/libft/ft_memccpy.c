/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:58:50 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 01:58:51 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
		if (dst2[x] == c)
		{
			x++;
			return (dst2 + x);
		}
		x++;
	}
	return (NULL);
}
