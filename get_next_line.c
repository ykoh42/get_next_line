/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoh <ykoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:01:51 by ykoh              #+#    #+#             */
/*   Updated: 2020/06/05 13:19:45 by ykoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_nl(char **line, char **tmpline)
{
	const char	*tmp = *tmpline;
	const char	*nl = ft_strchr(*tmpline, '\n');

	*line = ft_strndup(tmp, nl - tmp);
	*tmpline = ft_strndup(nl + 1, BUFFER_SIZE);
	free((void *)tmp);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmpline;
	char		buf[BUFFER_SIZE + 1];
	char		*nl;
	char		*tmp;
	ssize_t		readcnt;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	while ((!(nl = ft_strchr(tmpline, '\n')) &&
			(readcnt = read(fd, buf, BUFFER_SIZE)) != 0))
	{
		if (readcnt == -1)
			return (-1);
		buf[readcnt] = '\0';
		tmp = (tmpline) ? ft_strjoin(tmpline, buf) : ft_strndup(buf, readcnt);
		free(tmpline);
		tmpline = tmp;
	}
	if (nl)
		return (ft_nl(line, &tmpline));
	*line = (tmpline) ? tmpline : ft_strndup("", 1);
	tmpline = NULL;
	return (0);
}
