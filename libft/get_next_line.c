/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:36:30 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/09 17:04:49 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	extend_buf(int fd, char **buf)
{
	char	tmp_buf[BUFF_SIZE + 1];
	char	*tmp_ptr;
	int		amount;

	amount = read(fd, tmp_buf, BUFF_SIZE);
	tmp_buf[amount] = '\0';
	tmp_ptr = ft_strjoin(*buf, tmp_buf);
	free(*buf);
	*buf = tmp_ptr;
	return (amount == BUFF_SIZE);
}

static void	fd_add(t_fd **buf, int fd)
{
	(*buf) = (t_fd*)malloc(sizeof(t_fd));
	(*buf)->str = ft_strdup("");
	(*buf)->fd = fd;
	(*buf)->next = NULL;
}

static void	fd_find(t_fd **buf, int fd)
{
	t_fd *tmp;

	while ((*buf)->fd != fd)
	{
		if ((*buf)->next)
			*buf = (*buf)->next;
		else
		{
			fd_add(&tmp, fd);
			(*buf)->next = tmp;
			*buf = (*buf)->next;
		}
	}
}

int			find_nl(t_fd **buf)
{
	while (ft_strchr((*buf)->str, '\n') == NULL)
		if (!extend_buf((*buf)->fd, &(*buf)->str))
		{
			if (ft_strequ((*buf)->str, ""))
				return (1);
			return (0);
		}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd *first = NULL;
	t_fd		*buf;
	int			i;
	char		*tmp_ptr;

	if (!first)
		fd_add(&first, fd);
	buf = first;
	if (fd < 0 || read(fd, 0, 0) == -1)
		return (-1);
	fd_find(&buf, fd);
	if (find_nl(&buf))
		return (0);
	i = 0;
	while (buf->str[i] != '\n' && buf->str[i] != '\0')
		i++;
	*line = ft_strsub(buf->str, 0, i);
	tmp_ptr = ft_strsub(buf->str, i + 1, ft_strlen(buf->str) - i);
	free(buf->str);
	buf->str = tmp_ptr;
	return (1);
}
