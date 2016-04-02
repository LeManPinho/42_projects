/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 02:08:30 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 02:08:31 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	len;
	char	*dest;

	if (s == NULL)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	len = ft_strlen(s);
	while (*s && ft_isspace(s[--len]))
		;
	if (!(dest = ft_strnew(len)))
		return (NULL);
	dest = ft_strncpy(dest, s, len + 1);
	dest[len + 1] = '\0';
	return (dest);
}
