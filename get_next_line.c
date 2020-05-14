/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoh <ykoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:01:51 by ykoh              #+#    #+#             */
/*   Updated: 2020/06/04 20:50:45 by ykoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static char	*tmpbuf;
	char		buf[BUFFER_SIZE + 1];
	char		*nl;
	char		*tmp;
	ssize_t		readcnt;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!(nl = ft_strchr(tmpbuf, '\n')) &&
			(readcnt = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (readcnt == -1)
			return (-1);
		buf[readcnt] = '\0';
		tmp = (tmpbuf) ? ft_strjoin(tmpbuf, buf) : ft_strndup(buf, readcnt);
		free(tmpbuf);
		tmpbuf = tmp;
	}
	if (nl)
	{
		tmp = tmpbuf;
		*line = ft_strndup(tmp, nl - tmp);
		tmpbuf = ft_strndup(nl + 1, BUFFER_SIZE);
		free(tmp);
		return (1);
	}
	*line = (tmpbuf) ? tmpbuf : ft_strndup("", 1);
	free(tmpbuf);
	tmpbuf = NULL;
	return (0);
}
