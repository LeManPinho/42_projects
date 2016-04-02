/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:03:57 by hjacque           #+#    #+#             */
/*   Updated: 2016/03/25 18:25:23 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printl(t_info *l, t_max maxlen, int *state, char *blazz)
{
	ft_putstrspace(l->rights);
	printspace(ft_nbrlen(l->links, 10), maxlen.mlinks);
	ft_putnbr(l->links);
	if (state[G] == 0)
	{
		printspace(ft_strlen(l->pwd), maxlen.muser);
		ft_putstrspace(l->pwd);
	}
	if (state[G] == 1 && state[O] == 1)
		ft_putstr("  ");
	if (state[O] == 0)
	{
		printspace(ft_strlen(l->grp), maxlen.mgrp);
		ft_putstrspace(l->grp);
	}
	printspace(ft_nbrlen(l->bytes, 10), maxlen.mbytes);
	ft_putnbr(l->bytes);
	ft_putchar(' ');
	ft_putstrtimespace(ctime(&(l->mtime)));
	if (l->rights[0] == 'l')
	{
		ft_putstr(blazz);
		ft_putstr(" -> ");
		ft_putstr(l->linkname);
	}
}

void		printspace(int u, int k)
{
	int	i;

	i = 0;
	i = k - u;
	while (i >= 0)
	{
		ft_putchar(' ');
		i--;
	}
}

void		print(t_ls *l, int *state, char *path, t_max maxlen)
{
	t_info	*lol;

	if ((state[L] == 1) || (state[G] == 1))
		printtotal(l, path);
	while (l != NULL)
	{
		if ((state[L] == 1) || (state[G] == 1) || (state[O] == 1))
		{
			lol = fullinfo(((t_osef *)(l->data))->my_stat,\
				ft_strjoinslash(path, ((t_osef *)l->data)->name), state);
			printl(lol, maxlen, state, ((t_osef *)l->data)->name);
			if (lol->rights[0] != 'l')
				ft_putstr(((t_osef *)l->data)->name);
		}
		else
			ft_putstr(((t_osef *)l->data)->name);
		l = l->next;
		ft_putchar('\n');
	}
}

blkcnt_t	gettotal(struct stat sb, char *d_name)
{
	blkcnt_t	total;

	lstat(d_name, &sb);
	ft_memcpy(&(total), &(sb.st_blocks), sizeof(long int));
	return (total);
}

void		printtotal(t_ls *fck, char *path)
{
	blkcnt_t	tot;
	blkcnt_t	total;

	total = 0;
	while (fck != NULL)
	{
		tot = gettotal(((t_osef *)(fck->data))->my_stat,\
			ft_strjoinslash(path, ((t_osef *)fck->data)->name));
		total = total + tot;
		fck = fck->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	clearlst(fck);
}
