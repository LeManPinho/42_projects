/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:47:27 by hjacque           #+#    #+#             */
/*   Updated: 2015/03/26 14:49:43 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *str, int n)
{
	char	*result;
	int		i;

	if ((result = malloc(n + 1)) == NULL)
		return (NULL);
	i = -1;
	while (str[++i] && i < n)
		result[i] = str[i];
	result[i] = 0;
	return (result);
}
