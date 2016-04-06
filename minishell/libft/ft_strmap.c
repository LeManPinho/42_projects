/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 02:06:00 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 02:06:01 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	x;
	size_t	y;

	x = ft_strlen(s);
	str = ft_strnew(x);
	y = 0;
	while (s[y])
	{
		str[y] = (*f)(s[y]);
		y++;
	}
	return (str);
}
