/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/09/20 18:04:20 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		set_window_size(t_tout *tout)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	tout->width = window.ws_col;
	tout->height = window.ws_row;
}

void		clear_the_screen(t_tout *tout)
{
	int	i;

	i = 0;
	while (i < tout->height)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, i), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		i++;
	}
}

static int	can_print(t_tout *tout)
{
	int		nbcolumns;

	nbcolumns = tout->word_count / tout->height + 1;
	if (nbcolumns * tout->single_column_width <= tout->width)
		return (1);
	else
		return (0);
}

void		refresh_screen(int signum)
{
	t_tout	*tout;

	(void)signum;
	tout = reset_tout(NULL);
	set_window_size(tout);
	clear_the_screen(tout);
	if (can_print(tout))
		printarg(tout);
	else
		ft_putstr_fd("Pas assez de place mon ami.", 2);
}
