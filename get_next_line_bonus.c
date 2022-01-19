
#include "get_next_line.h"

int	ft_nl(char	*buf)
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

char	*get_next_line(int fd)
{
	static char	*(buffer[1024]);
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			len;
	int			nb;

	if ((fd < 0 && fd < 1024) || BUFFER_SIZE < 1)
		return (NULL);
	len = ft_nl(buffer[fd]);
	if (len)
	{
		tmp = ft_substr(buffer[fd], 0, len);
		buffer[fd] = ft_buffer_rm(buffer[fd], len);
		return (tmp);
	}
	nb = read(fd, buf, BUFFER_SIZE);
	buf[nb] = '\0';
	if (0 < nb && nb <= BUFFER_SIZE)
	{
		buffer[fd] = ft_buffer_add(buffer[fd], buf);
		return (get_next_line(fd));
	}
	tmp = buffer[fd];
	buffer[fd] = NULL;
	return (tmp);
}
