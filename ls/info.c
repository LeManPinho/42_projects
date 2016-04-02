/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:36:37 by hjacque           #+#    #+#             */
/*   Updated: 2016/04/02 12:49:30 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info			*fullinfo(struct stat sb, char *d_name, int *state)
{
	t_info		*ret;

	lstat(d_name, &sb);
	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret = fillrights(ret, sb);
	ret = fillinfo(ret, sb, state);
	ret = fillinfo2(ret, sb, state, d_name);
	return (ret);
}

void			getmaxlen(t_info *ret, t_max *maxlen, int *state)
{
	if (ft_nbrlen(ret->links, 10) > maxlen->mlinks)
		maxlen->mlinks = ft_nbrlen(ret->links, 10);
	if (state[G] == 0)
	{
		if (ft_strlen(ret->pwd) > maxlen->muser)
			maxlen->muser = ft_strlen(ret->pwd);
	}
	if (state[O] == 0)
	{
		if (ft_strlen(ret->grp) > maxlen->mgrp)
			maxlen->mgrp = ft_strlen(ret->grp);
	}
	if (ft_nbrlen(ret->bytes, 10) > maxlen->mbytes)
		maxlen->mbytes = ft_nbrlen(ret->bytes, 10);
}

t_info			*fillrights(t_info *ret, struct stat sb)
{
	if ((ret->rights = malloc(sizeof(char) * 11)) == NULL)
		return (NULL);
	if (S_ISDIR(sb.st_mode))
		ret->rights[0] = 'd';
	else if (S_ISLNK(sb.st_mode))
		ret->rights[0] = 'l';
	else
		ret->rights[0] = '-';
	ret->rights[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
	ret->rights[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
	ret->rights[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
	ret->rights[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
	ret->rights[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
	ret->rights[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
	ret->rights[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
	ret->rights[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
	ret->rights[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';
	ret->rights[10] = '\0';
	return (ret);
}

t_info			*fillinfo(t_info *ret, struct stat sb, int *state)
{
	struct group	*group;
	struct passwd	*passwd;

	ft_memcpy(&(ret->links), &(sb.st_nlink), sizeof(long unsigned int));
	if (state[G] == 0)
	{
		passwd = getpwuid(sb.st_uid);
		if (!(ret->pwd = malloc(ft_strlen(passwd->pw_name) + 1)))
			return (NULL);
		ft_memcpy(ret->pwd, passwd->pw_name, ft_strlen(passwd->pw_name) + 1);
	}
	if (state[O] == 0)
	{
		group = getgrgid(sb.st_gid);
		if (!(ret->grp = malloc(ft_strlen(group->gr_name) + 1)))
			return (NULL);
		ft_memcpy(ret->grp, group->gr_name, ft_strlen(group->gr_name) + 1);
	}
	ft_memcpy(&(ret->bytes), &(sb.st_size), sizeof(long int));
	return (ret);
}

t_info			*fillinfo2(t_info *ret, struct stat sb, int *state, char *blaze)
{
	int		i;

	if (state[U] == 1)
		ft_memcpy(&(ret->mtime), &(sb.st_atime), sizeof(long int));
	else
		ft_memcpy(&(ret->mtime), &(sb.st_mtime), sizeof(long int));
	if (S_ISLNK(sb.st_mode))
	{
		if (!(ret->linkname = malloc(256)))
			return (NULL);
		if ((i = readlink(blaze, ret->linkname, 256)) == -1)
			return (NULL);
		ret->linkname[i] = '\0';
	}
	return (ret);
}
