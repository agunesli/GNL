/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:27:19 by agunesli          #+#    #+#             */
/*   Updated: 2022/02/14 21:13:21 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
<<<<<<< HEAD
	static	char	*(buffer[1024]);
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;
	int				len_nb[2];

	if (fd < 0 || 1023 < fd || BUFFER_SIZE < 1)
		return (NULL);
	len_nb[0] = ft_nl(buffer[fd]);
	if (len_nb[0])
=======
	static char	*buffer[1024];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			len;
	int			nb;

	if ((fd < 0 || 1024 < fd) || BUFFER_SIZE < 1)
		return (NULL);
	len = ft_found_nl(buffer[fd]);
	if (len)
>>>>>>> cc64ff92ee066a218c0fcecbfcb842c581beab9a
	{
		tmp = ft_substr(buffer[fd], 0, len_nb[0]);
		buffer[fd] = ft_buffer_rm(buffer[fd], len_nb[0]);
		return (tmp);
	}
<<<<<<< HEAD
	len_nb[1] = read(fd, buf, BUFFER_SIZE);
	if (len_nb[1] > 0)
		buf[len_nb[1]] = '\0';
	if (0 < len_nb[1] && len_nb[1] <= BUFFER_SIZE)
=======
	nb = read(fd, buf, BUFFER_SIZE);
	if (nb > -1)
		buf[nb] = '\0';
	if (0 < nb && nb <= BUFFER_SIZE)
>>>>>>> cc64ff92ee066a218c0fcecbfcb842c581beab9a
	{
		buffer[fd] = ft_buffer_add(buffer[fd], buf);
		return (get_next_line(fd));
	}
	return (ft_buffer_end(buffer[fd]));
}
