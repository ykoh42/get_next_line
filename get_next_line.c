/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoh <ykoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 11:44:46 by ykoh              #+#    #+#             */
/*   Updated: 2020/05/05 08:18:15 by ykoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"
#define BUFFER_SIZE 1000

static char	*ft_parser(char *line, char *buf, char *nl)
{
	char	*tmp;

	if (nl == NULL)
		tmp = ft_strjoin(line, buf);
	else
	{
		tmp = ft_strndup(buf, nl - buf + 1);
		free(line);
		ft_strlcpy(buf, nl + 1, BUFFER_SIZE);
	}
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		readcnt;
	char		*nl;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(*line = ft_strndup("", 0)))
		return (-1);
	//버퍼가 비었으면
	while (buf[0] == '\0' && ((readcnt = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[readcnt] = '\0';
		if ((nl = ft_strchr(buf, '\n')))
		{
			if (!(*line = ft_parser(*line, buf, nl)))
				return (-1);
			return (1);
		}
		else
		{
			if (!(*line = ft_parser(*line, buf, nl)))
				return (-1);
			buf[0] = '\0';
		}		
	}
	//버퍼가 안비었으면
	while (buf[0] != '\0')
	{
		if ((nl = ft_strchr(buf, '\n')))
		{
			if (!(*line = ft_parser(*line, buf, nl)))
				return (-1);
			return (1);
		}
		else
		{
			if (!(*line = ft_parser(*line, buf, nl)))
				return (-1);
			buf[0] = '\0';
		}		
	}
	return (readcnt);
}
