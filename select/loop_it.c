/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/09/21 23:52:06 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	select_deselect(t_tout *tout)
{
	if (tout->white[tout->word_cursor] == 1)
		tout->white[tout->word_cursor] = 0;
	else
		tout->white[tout->word_cursor] = 1;
	if (tout->word_cursor == tout->word_count - 1)
		tout->word_cursor = 0;
	else
		tout->word_cursor++;
}

static void	up_down(t_tout *tout, int key)
{
	if (key == KEY_DOWN)
	{
		if (tout->word_cursor == tout->word_count - 1)
			tout->word_cursor = 0;
		else
			tout->word_cursor++;
	}
	else if (key == KEY_UP)
	{
		if (tout->word_cursor == 0)
			tout->word_cursor = tout->word_count - 1;
		else
			tout->word_cursor--;
	}
}

static void	left_right(t_tout *tout, int key)
{
	int		new_word;
	int		pos_top;

	pos_top = tout->word_cursor % tout->height;
	if (key == KEY_RIGHT)
	{
		new_word = tout->word_cursor + tout->height;
		if (new_word >= tout->word_count)
			tout->word_cursor = pos_top;
		else
			tout->word_cursor = new_word;
	}
	else if (key == KEY_LEFT)
	{
		new_word = tout->word_cursor - tout->height;
		if (new_word < 0)
		{
			while (new_word < tout->word_count)
				new_word = new_word + tout->height;
			tout->word_cursor = new_word - tout->height;
		}
		else
			tout->word_cursor = new_word;
	}
}

static void	remove_word(t_tout *tout)
{
	remove_from_array(tout->word_cursor, (void*)tout->words
						, sizeof(char*), tout->word_count);
	remove_from_array(tout->word_cursor, (void*)tout->white
						, sizeof(int), tout->word_count);
	tout->word_count--;
	if (tout->word_count <= 0)
		abort_exit(0);
	if (tout->word_cursor >= tout->word_count)
		tout->word_cursor = 0;
}

void		loop_it(t_tout *tout)
{
	unsigned long	key;
	int				refresh;

	while ((key = 0) || (read(0, &key, 6)) != 0)
	{
		refresh = 1;
		if (key == KEY_ESCAPE || key == 'q')
			abort_exit(0);
		else if (key == KEY_SPACE)
			select_deselect(tout);
		else if (key == KEY_ENTER)
			print_white(tout);
		else if (key == KEY_UP || key == KEY_DOWN)
			up_down(tout, key);
		else if (key == KEY_LEFT || key == KEY_RIGHT)
			left_right(tout, key);
		else if (key == KEY_BACKSPACE || key == KEY_DELETE)
			remove_word(tout);
		else
			refresh = 0;
		if (refresh)
			refresh_screen(0);
	}
}
