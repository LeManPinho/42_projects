/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:49:34 by hjacque           #+#    #+#             */
/*   Updated: 2016/01/25 13:05:59 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long nbr, int base)
{
	int	len;

	len = 1;
	while (nbr > (base - 1) || nbr < -(base - 1))
	{
		nbr = nbr / base;
		len++;
	}
	return (len);
}
