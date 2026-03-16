/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:55:46 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/27 10:14:19 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	expand_buffer(char **buf, size_t *size, size_t len)
{
	char	*tmp;
	size_t	i;

	*size *= 2;
	tmp = malloc(*size);
	if (!tmp)
		return (0);
	i = 0;
	while (i < len)
	{
		tmp[i] = (*buf)[i];
		i++;
	}
	free(*buf);
	*buf = tmp;
	return (1);
}

static int	read_char(ssize_t *n, char *c)
{
	*n = read(0, c, 1);
	return (*n == 1);
}

static char	*init_buffer(size_t *size, size_t *len)
{
	*size = 8;
	*len = 0;
	return (malloc(*size));
}

int	read_line(char **line)
{
	char	*buf;
	size_t	size;
	size_t	len;
	ssize_t	n;
	char	c;

	buf = init_buffer(&size, &len);
	if (!buf)
		return (-1);
	while (read_char(&n, &c) && c != '\n')
	{
		if (len + 1 >= size && !expand_buffer(&buf, &size, len))
			return (free(buf), -1);
		buf[len++] = c;
	}
	if (n < 0 || (n == 0 && len > 0))
		return (free(buf), -1);
	if (len == 0 && n == 0)
		return (free(buf), 0);
	if (len == 0)
		return (free(buf), -1);
	buf[len] = '\0';
	*line = buf;
	return (1);
}
