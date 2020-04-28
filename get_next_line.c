/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoh <ykoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 11:44:46 by ykoh              #+#    #+#             */
/*   Updated: 2020/05/02 16:39:59 by ykoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#define BUFFER_SIZE 1000000000

static char	*lineupdate(char *line, char *tmp)
{
	char	*updated;

	updated = ft_strjoin(line, tmp);
	free(line);
	return (updated);
}

int			get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*nl;
	char	*tmp;
	ssize_t	readcnt;

	if (!(*line = ft_strdup("")))
		return (-1);
	if (ft_strlen(buf))
	{
		while (ft_strlen(buf))
		{
			// nl 검사
			if ((nl = ft_strchr(buf, '\n')))
			{
				//nl있으면 붙이고 떙기고 리턴
				if (!(tmp = ft_substr(buf, 0, nl - buf + 1)))
						return (-1);
				if (!(*line = lineupdate(*line, tmp)))
						return (-1);
				free(tmp);
				ft_memcpy(buf, nl + 1, BUFFER_SIZE - (nl - buf));
				return (1);
			}
			else
			{
				//nl 없으면 붙이고 루프 반복
				if (!(*line = lineupdate(*line, buf)))
					return (-1);
				buf[0] = '\0';
			}
		}
	}
	while ((readcnt = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (readcnt == -1)
			break ;
		buf[readcnt] = '\0';
		// nl 검사
		if ((nl = ft_strchr(buf, '\n')))
		{
			//nl있으면 붙이고 떙기고 리턴
			if (!(tmp = ft_substr(buf, 0, nl - buf + 1)))
					return (-1);
			if (!(*line = lineupdate(*line, tmp)))
					return (-1);
			free(tmp);
			ft_memcpy(buf, nl + 1, BUFFER_SIZE - (nl - buf));
			return (1);
		}
		else
		{
			//nl 없으면 붙이고 루프 반복
			if (!(*line = lineupdate(*line, buf)))
				return (-1);
			buf[0] = '\0';
		}
	}
	free(*line);
	return (readcnt);
}
