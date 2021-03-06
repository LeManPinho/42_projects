/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 02:06:23 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 02:06:23 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t i;
	size_t x;

	i = 0;
	x = 0;
	while (s1[i])
		i++;
	while ((s2[x]) && x < n)
	{
		s1[i] = s2[x];
		i++;
		x++;
	}
	s1[i] = '\0';
	return (s1);
}
