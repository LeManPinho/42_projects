/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/06/27 14:48:49 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			main(int ac, char **av)
{
	t_tout	*tout;

	tout = inittout(ac, av);
	tout->fd = 0;
	if (ac < 2)
		ft_putendl_fd_exit("Usage: ft_select [parameters]", 2, 1);
	if (!isatty(tout->fd))
		return (0);
	reset_tout(tout);
	init_term_data(tout);
	set_signals(&restart);
	refresh_screen(0);
	loop_it(tout);
	return (0);
}
