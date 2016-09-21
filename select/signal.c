/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/09/20 16:30:48 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_signals(void (*restart_function)(int))
{
	signal(SIGWINCH, refresh_screen);
	signal(SIGCONT, restart_function);
	signal(SIGTSTP, abort_no_exit);
	signal(SIGINT, abort_exit);
	signal(SIGINT, abort_exit);
	signal(SIGHUP, abort_exit);
	signal(SIGTERM, abort_exit);
	signal(SIGSEGV, abort_exit);
	signal(SIGQUIT, abort_exit);
	signal(SIGFPE, abort_exit);
	signal(SIGALRM, abort_exit);
	signal(SIGKILL, abort_exit);
	signal(SIGABRT, abort_exit);
	signal(SIGUSR1, abort_exit);
	signal(SIGUSR2, abort_exit);
}

void	restart(int signum)
{
	t_tout	*tout;

	(void)signum;
	tout = reset_tout(NULL);
	init_term_data(tout);
	set_signals(&restart);
	refresh_screen(0);
}
