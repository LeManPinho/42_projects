/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 02:06:09 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 02:06:10 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			x;
	size_t			y;
	unsigned int	i;

	x = ft_strlen(s);
	str = ft_strnew(x);
	y = 0;
	i = 0;
	while (s[y])
	{
		str[y] = (*f)(i, s[y]);
		y++;
		i++;
	}
	return (str);
}
