#ifndef 21SH_H
# define 21SH_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <signal.h>
# include <dirent.h>

# define WORDS		0
# define DQUOTE		1
# define BQUOTE		2
# define SYMBOL		3
# define END_LINE	4

typedef struct 			s_lexlst
{
	int		type;
	char	*lexeme;
}						t_lexlst;

typedef struct 			s_all
{
	char				*line;
	char				*epured_line;
}						t_all;

#endif