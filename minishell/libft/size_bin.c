/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:29:39 by hjacque           #+#    #+#             */
/*   Updated: 2016/01/25 13:30:35 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_bin(unsigned int nbr)
{
	if (nbr <= 64)
		return (1);
	else if (nbr <= 1024)
		return (2);
	else if (nbr <= 32768)
		return (3);
	else
		return (4);
}