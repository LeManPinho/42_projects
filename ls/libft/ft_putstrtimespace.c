/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtimespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 02:02:09 by hjacque           #+#    #+#             */
/*   Updated: 2014/11/13 02:02:09 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrtimespace(char const *s)
{
	int	x;

	x = 0;
	while (x < 4)
		x++;
	while (x < 16)
	{
		ft_putchar(s[x]);
		x++;
	}
	ft_putchar(' ');
}
