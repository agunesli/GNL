/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:27:19 by agunesli          #+#    #+#             */
/*   Updated: 2022/01/21 14:18:23 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_found_nl(char	*buf)
{
	int	len;

	len = 0;
	if (buf == NULL)
		return (0);
	while (buf[len])
	{
		if (buf[len] == '\n')
			return (len + 1);
		len++;
	}
	return (0);
}

char	*ft_buffer_add(char *buffer, char *buf)
{
	char	*tmp;

	tmp = buffer;
	buffer = ft_strjoin(tmp, buf);
	free(tmp);
	return (buffer);
}

char	*ft_buffer_rm(char *buffer, int len)
{
	char	*tmp;

	tmp = buffer;
	buffer = ft_substr(tmp, len, ft_strlen(tmp));
	free(tmp);
	return (buffer);
}

char	*ft_buffer_end(char *buffer)
{
	char	*tmp;

	tmp = buffer;
	buffer = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			len;
	int			nb;

	if ((fd < 0 || 1024 < fd) || BUFFER_SIZE < 1)
		return (NULL);
	len = ft_found_nl(buffer[fd]);
	if (len)
	{
		tmp = ft_substr(buffer[fd], 0, len);
		buffer[fd] = ft_buffer_rm(buffer[fd], len);
		return (tmp);
	}
	nb = read(fd, buf, BUFFER_SIZE);
	if (nb > -1)
		buf[nb] = '\0';
	if (0 < nb && nb <= BUFFER_SIZE)
	{
		buffer[fd] = ft_buffer_add(buffer[fd], buf);
		return (get_next_line(fd));
	}
	return (ft_buffer_end(buffer[fd]));
}
