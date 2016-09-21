/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrchelou.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 13:42:12 by hjacque           #+#    #+#             */
/*   Updated: 2016/01/11 14:15:42 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrchelou(long long nbr, int base, int caps)
{
	char c;

	if (nbr > base - 1 || nbr < -(base - 1))
		ft_putnbrchelou(nbr / ((nbr < 0) ? -base : base), base, caps);
	c = nbr % base * ((nbr < 0) ? -1 : 1);
	if (c > 9 && caps == 0)
		c = c - 10 + 'a';
	else if (c > 9 && caps == 1)
		c = c - 10 + 'A';
	else
		c = c + '0';
	(void)write(1, &c, 1);
}
