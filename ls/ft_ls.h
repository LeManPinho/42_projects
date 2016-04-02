/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:53:06 by hjacque           #+#    #+#             */
/*   Updated: 2016/04/02 16:29:33 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <grp.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <pwd.h>
# include <sys/stat.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>

# define L 0
# define GR 1
# define A 2
# define R 3
# define T 4
# define G 5
# define O 6
# define F 7
# define D 8
# define U 9

typedef struct		s_stock
{
	int				i;
	int				p;
	int				u;
}					t_stock;

typedef struct		s_max
{
	int				mlinks;
	unsigned int	muser;
	unsigned int	mgrp;
	int				mbytes;
}					t_max;

typedef struct		s_info
{
	char			*grp;
	char			*pwd;
	time_t			mtime;
	char			*rights;
	off_t			bytes;
	nlink_t			links;
	char			*linkname;
}					t_info;

typedef struct		s_osef
{
	char			*name;
	struct stat		my_stat;
}					t_osef;

typedef struct		s_ls
{
	void			*data;
	struct s_ls		*next;
}					t_ls;

blkcnt_t			gettotal(struct stat sb, char *d_name);
int					classtime(void *a, void *b);
int					classtimerev(void *a, void *b);
int					classalpha(void *a, void *b);
int					classalpharev(void *a, void *b);
int					getargopt(int ac, char **av, int *state, char **path);
int					indexof(const char *str, const char c);
t_info				*fullinfo(struct stat sb, char *d_name, int *state);
void				recursive(char *path, int *state, int n);
void				swap(t_ls *a, t_ls **begin);
t_ls				*addelem(t_ls **begin, void *data);
void				clearlst(t_ls *begin);
void				sortlist(t_ls **begin, int (*sort)(void *, void *));
void				sortlistrev(t_ls **begin, int (*sort)(void *, void *));
void				print(t_ls *l, int *state, char *path, t_max maxlen);
void				printtotal(t_ls *fck, char *path);
void				printl(t_info *l, t_max maxlen, int *state, char *blazz);
void				printspace(int u, int k);
void				getmaxlen(t_info *ret, t_max *maxlen, int *state);
t_max				findmax(t_ls *l, char *path, int *state);
void				recursive2(t_ls *a, int *state, char *path);
t_ls				*sorta(t_ls *a, int *state);
t_info				*fillrights(t_info *ret, struct stat sb);
t_info				*fillinfo(t_info *ret, struct stat sb, int *state);
t_info				*fillinfo2(t_info *ret, struct stat sb, int *state, \
						char *blaze);
void				launch(char **path, int *state);
void				freeinfo(t_info *ret);
void				pathnames(char *path, int *state, int n);
void				pathmalloc(int i, int ac, char **av, char **path);
void				printfile(int *state, char *path, struct stat stat, \
						t_max maxlen);
t_max				findmaxfile(char *path, int *state, struct stat stat);
t_ls				*reverselist(t_ls *a);
int					classtimeaccess(void *a, void *b);
int					classtimeaccessr(void *a, void *b);
t_ls				*filla(int *state, t_ls *a, char *path, struct dirent *dir);
void				printerror(char **av, int i, int u);
void				gopath(char *path, int *state, struct stat stat, int i);
void				gopath2(char *path, int *state, struct stat stat, int i);
void				rilimate(char *path, int *state, int i);

#endif
