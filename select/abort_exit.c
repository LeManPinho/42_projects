/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/09/20 16:15:23 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	abort_no_exit(int signum)
{
	t_tout	*tout;
	char	tmp[2];

	(void)signum;
	tout = reset_tout(NULL);
	clear_the_screen(tout);
	tout->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &(tout->term));
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	if (signum == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		tmp[0] = tout->term.c_cc[VSUSP];
		tmp[1] = 0;
		ioctl(0, TIOCSTI, tmp);
	}
}

void	abort_exit(int signum)
{
	abort_no_exit(signum);
	exit(0);
}
