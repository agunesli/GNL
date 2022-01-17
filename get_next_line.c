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

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*buf;
	char		*tmp;
	char		*sub;
	size_t		len;
	int			nb;

	if (fd == -1)
		return (NULL);
	len = ft_nl(buffer);
	if (len)
	{
		sub = ft_substr(buffer, 0, len);
		tmp = buffer;
		buffer = ft_substr(tmp, len, BUFFER_SIZE);
		free(tmp);
		return (sub);
	}
	buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nb = read(fd, buf, BUFFER_SIZE);
	buf[nb] = '\0';
	if (0 < nb && nb <= BUFFER_SIZE)
	{
		tmp = buffer;
		buffer = ft_strjoin(tmp, buf);
		free(tmp);
		free(buf);
		return (get_next_line(fd));
	}
	else if (!nb && buffer != NULL)
	{
		free(buf);
		tmp = buffer;
		buffer = NULL;
		return (tmp);
	}
//	len = ft_nl(buf);
/*	if (nb == BUFFER_SIZE)
	{
		if (0 < len && len < BUFFER_SIZE + 1)
		{
			tmp = ft_substr(buf, 0, len);
			sub = ft_strjoin(buffer, tmp);
			free(tmp);
			free(buffer);
			buffer = ft_substr(buf, len, BUFFER_SIZE);
			free(buf);
			return (sub);
		}
		else if (!len)
		{
			tmp = buffer;
			buffer = ft_strjoin(tmp, buf);
			free(tmp);
			free(buf);
			return (get_next_line(fd));
		}
		else
			return (NULL);
	}
	else if (0 < nb && nb < BUFFER_SIZE)
	{
		if (!len)
			len = nb;
		tmp = ft_substr(buf, 0, len);
		sub = ft_strjoin(buffer, tmp);
		free(tmp);
		free(buffer);
		free(buf);
		return (sub);
	}*/
	else
	{
		free(buf);
		return (buffer);
	}
}
