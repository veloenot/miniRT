/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:08:21 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:08:23 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	ft_read_gnl(int fd, char **buf, size_t *count, char **tmp)
{
	*count = read(fd, *buf, BUFFER_SIZE);
	if (*count == 0)
		return (0);
	if (*count == (size_t)-1)
	{
		free (*tmp);
		*tmp = NULL;
		free (*buf);
		return (-1);
	}
	return (*count);
}

int	ft_errors_gnl(int fd, char **line, char **tmp, char **buf)
{
	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	*buf = ft_ccalloc(BUFFER_SIZE + 1, sizeof(char));
	if (*tmp == NULL)
		*tmp = ft_ccalloc(1, sizeof(char));
	if (*buf == NULL || *tmp == NULL)
	{
		free(*buf);
		free(*tmp);
		return (-1);
	}
	return (0);
}

int	ft_result(size_t *count, char **tmp, char **line, char **buf)
{
	int		i;
	char	*t_tmp;

	t_tmp = *tmp;
	if (*count == 0 && ft_strrchr(t_tmp, '\n') == NULL)
	{
		*line = t_tmp;
		*tmp = NULL;
		return (0);
	}
	i = 0;
	while (t_tmp[i] != '\n')
		i++;
	t_tmp[i] = '\0';
	*buf = ft_ccalloc(i + 1, sizeof(char));
	if (*buf == NULL)
	{
		free (*tmp);
		*tmp = NULL;
		return (-1);
	}
	i = ft_strlcpy_gnl(*buf, t_tmp) + 1;
	*line = *buf;
	ft_strlcpy_gnl(t_tmp, &t_tmp[i]);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*tmp;
	char		*join_buf;
	size_t		count;

	if (ft_errors_gnl(fd, line, &tmp, &buf) == -1)
		return (-1);
	while (ft_read_gnl(fd, &buf, &count, &tmp) > 0)
	{
		join_buf = ft_strjoin_gnl(tmp, buf);
		free(tmp);
		if (join_buf == NULL)
		{
			free (buf);
			return (-1);
		}
		tmp = join_buf;
		if (ft_strrchr(tmp, '\n') != NULL)
			break ;
		ft_bzero(buf, ft_strlen(buf));
	}
	if (count == (size_t)-1)
		return (-1);
	free (buf);
	return (ft_result(&count, &tmp, line, &buf));
}
