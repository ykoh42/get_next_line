/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoh <ykoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:01:51 by ykoh              #+#    #+#             */
/*   Updated: 2020/05/30 18:48:10 by ykoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		readcnt;
	char		*nl;
	char		*tmp;

	readcnt = 0;
	while (!(nl = ft_strchr(str, '\n')) &&
			(readcnt = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readcnt] = 0;
		tmp = (str) ? ft_strjoin(str, buf) : buf;
		free(str);
		str = tmp;
	}
	if (nl)
	{
		*line = ft_strndup(str, nl - str + 1);
		tmp = str;
		str = ft_strndup(nl + 1, BUFFER_SIZE);
		free(tmp);
		return (1);
	}
	if (readcnt == 0)
	{
		*line = str;
		str = NULL;
	}
	return (readcnt);
}
