/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrprec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 13:24:41 by hjacque           #+#    #+#             */
/*   Updated: 2016/01/25 13:06:36 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrprec(long long nbr, int *state, int base, int caps)
{
	int	useme;
	int	ret;

	ret = ft_nbrlen(nbr, base);
	useme = -1;
	if (nbr < 0)
		(void)write(1, "-", 1);
	else if (state[3] != 0)
		(void)write(1, "+", 1);
	else if (state[3] != 0 && nbr == 0)
		(void)write(1, " ", 1);
	else if (state[4] != 0)
	{
		(void)write(1, " ", 1);
		state[6]--;
	}
	if (state[6] > ret)
		while (++useme != state[6] - ret)
			(void)write(1, "0", 1);
	ft_putnbrchelou(nbr, base, caps);
}
