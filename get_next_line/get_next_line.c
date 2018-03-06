/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:22:18 by wzaim             #+#    #+#             */
/*   Updated: 2017/12/04 13:26:00 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strichr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	swap_join(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(tmp, buf);
	free(tmp);
}

int		handle_buff(int fd, char **line)
{
	static char	buf[FD_MAX][BUFF_SIZE + 1];
	int			idx[2];

	if ((buf[fd]) && (idx[1] = ft_strichr(buf[fd], '\n')) != -1)
	{
		buf[fd][idx[1]] = '\0';
		if (!(*line))
			*line = ft_strdup(buf[fd]);
		else
			swap_join(line, buf[fd]);
		ft_strcpy(buf[fd], buf[fd] + idx[1] + 1);
		ft_strclr(buf[fd] + (BUFF_SIZE - idx[1] - 1));
		return (1);
	}
	if (buf[fd] && (idx[1] == -1) && (*line))
		swap_join(line, buf[fd]);
	else if (idx[1] == -1 && !(*line))
		*line = ft_strdup(buf[fd]);
	ft_strclr(buf[fd]);
	if ((idx[0] = read(fd, buf[fd], BUFF_SIZE)) > 0)
	{
		buf[fd][idx[0]] = '\0';
		return (handle_buff(fd, line));
	}
	return ((*line[0]) ? 1 : idx[0]);
}

int		get_next_line(const int fd, char **line)
{
	if (fd < 0 || fd >= FD_MAX - 1 || !(line))
		return (-1);
	*line = NULL;
	return (handle_buff(fd, line));
}
