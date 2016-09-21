/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:53:02 by hjacque           #+#    #+#             */
/*   Updated: 2016/09/20 16:25:51 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <signal.h>

# define BUFFADDR &buffer

char g_term_buffer[2048];

# define KEY_ESCAPE 0x1B
# define KEY_SPACE 0x20
# define KEY_UP 0x415B1B
# define KEY_DOWN 0x425B1B
# define KEY_RIGHT 0x435B1B
# define KEY_LEFT 0x445B1B
# define KEY_ENTER 0xA
# define KEY_BACKSPACE 0x7F
# define KEY_DELETE 0x7E335B1B

typedef struct			s_tout
{
	int					fd;
	char				**words;
	int					height;
	int					width;
	int					word_count;
	int					single_column_width;
	int					word_cursor;
	int					*white;
	struct termios		term;
}						t_tout;

void					abort_exit(int signum);
void					abort_no_exit(int signum);
void					set_signals(void (*restart_function)(int));
int						get_longest_word(t_tout *tout);
void					refresh_screen(int	signum);
void					loop_it(t_tout *tout);
void					init_term_data(t_tout *tout);
t_tout					*inittout(int ac, char **av);
void					set_window_size(t_tout *tout);
void					clear_the_screen(t_tout *tout);
t_tout					*reset_tout(t_tout *new_tout);
void					printarg(t_tout *tout);
void					restart(int signum);
void					print_white(t_tout *tout);

#endif
