/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 02:04:21 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 02:04:21 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*s2;
	int		x;

	x = ft_strlen(s1);
	s2 = malloc(sizeof(*s1) * (x + 1));
	if (s2 == '\0')
		return (0);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
