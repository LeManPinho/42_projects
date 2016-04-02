/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 02:06:52 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 02:06:52 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	int		i;
	char	*x;

	x = dest;
	i = 0;
	if (n > 0 && src[i] != '\0')
	{
		while (n > 0 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
			n--;
		}
	}
	if (n > 0)
	{
		while (n > 0)
		{
			dest[i] = '\0';
			i++;
			n--;
		}
	}
	return (x);
}
