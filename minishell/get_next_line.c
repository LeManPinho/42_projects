/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:44:56 by apinho            #+#    #+#             */
/*   Updated: 2016/05/03 15:01:45 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		endit(char **line, char **stock)
{
	size_t			len;
	char			*tempo;

	len = ft_strchr(*stock, '\n') - *stock;
	tempo = *stock;
	*line = ft_strsub(tempo, 0, len);
	*stock = ft_strdup(tempo + len + 1);
	free(tempo);
}

static int		endoffile(char **line, char **stock)
{
	if (ft_strchr(*stock, '\n') != NULL)
	{
		endit(line, stock);
		return (1);
	}
	*line = ft_strdup(*stock);
	ft_strdel(stock);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static char		*stock = NULL;
	char			*tempo;

	ret = 0;
	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (stock == NULL)
		stock = ft_strnew(BUFF_SIZE + 1);
	while (stock != NULL
			&& ft_strchr(stock, '\n') == NULL
			&& ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		tempo = stock;
		stock = ft_strjoin(tempo, buf);
		free(tempo);
	}
	if (ret == -1)
		return (-1);
	if (ret == 0)
		return (endoffile(line, &stock));
	endit(line, &(stock));
	return (1);
}
