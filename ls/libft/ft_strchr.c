/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 02:02:41 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 02:02:56 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char const)c)
			return ((char *)s);
		s++;
	}
	if ((char const)c == *s)
		return ((char *)s);
	return (NULL);
}
