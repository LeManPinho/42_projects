/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/09/20 16:22:28 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_term_data(t_tout *tout)
{
	char		*name_term;

	if (!(name_term = getenv("TERM")))
		ft_putendl_exit("Error getting env->TERM", 1);
	if (tgetent(g_term_buffer, name_term) <= 0)
		ft_putendl_fd_exit("Error getting env->TERM", 2, 1);
	tcgetattr(0, &tout->term);
	tout->term.c_lflag &= ~(ICANON);
	tout->term.c_lflag &= ~(ECHO);
	tout->term.c_cc[VMIN] = 1;
	tout->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &tout->term) == -1)
		exit(1);
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
}
