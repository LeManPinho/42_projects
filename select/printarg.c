/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/09/20 18:04:37 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		turn_on_special_text(t_tout *tout, int current)
{
	if (tout->white[current] == 1)
		ft_putstr_fd(tgetstr("so", NULL), 2);
	if (tout->word_cursor == current)
		ft_putstr_fd(tgetstr("us", NULL), 2);
}

static void		turn_off_special_text(t_tout *tout, int current)
{
	if (tout->word_cursor == current)
		ft_putstr_fd(tgetstr("ue", NULL), 2);
	if (tout->white[current] == 1)
		ft_putstr_fd(tgetstr("se", NULL), 2);
}

void			printarg(t_tout *tout)
{
	int		row;
	int		column;
	int		current;

	row = 0;
	while (row < tout->height && row < tout->word_count)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, row), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		column = 0;
		while (((current = (tout->height * column) + row)) < tout->word_count)
		{
			turn_on_special_text(tout, current);
			ft_putstr_fd(tout->words[current], 2);
			turn_off_special_text(tout, current);
			ft_putcharn_fd(' ', tout->single_column_width
							- ft_strlen(tout->words[current]), 2);
			column++;
		}
		row++;
	}
}

void			print_white(t_tout *tout)
{
	int		i;
	int		space;

	abort_no_exit(0);
	i = 0;
	space = 0;
	while (i < tout->word_count)
	{
		if (tout->white[i] == 1)
		{
			if (space)
				ft_putchar(' ');
			ft_putstr(tout->words[i]);
			space = 1;
		}
		i++;
	}
	exit(0);
}
