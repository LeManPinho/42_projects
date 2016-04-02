/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:59:03 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 01:59:04 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scp;
	size_t			x;

	x = 0;
	scp = (unsigned char *)s;
	while (x < n)
	{
		if (*scp == (unsigned char)c)
			return ((void *)scp);
		scp++;
		x++;
	}
	return (NULL);
}
