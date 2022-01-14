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
	static char	*buffer;
	char		*buf;
	char		*tmp;
	char		*sub;
	size_t		len;
	int			nb;

//	printf("%s\n",buffer);
	if (fd == -1)
		return (NULL);
	len = ft_nl(buffer);
//	printf("%lu\n", len);
	if (len)
	{
		tmp = buffer;
		buffer = ft_substr(buf, len, BUFFER_SIZE);
		sub = ft_substr(tmp, 0, len);
		free(tmp);
		return (sub);
	}
	buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nb = read(fd, buf, BUFFER_SIZE);
	len = ft_nl(buf);
	if (nb == BUFFER_SIZE)
	{
		if (len < BUFFER_SIZE)
		{
			tmp = ft_substr(buf, 0, len);
			sub = ft_strjoin(buffer, tmp);
			free(tmp);
			free(buffer);
			buffer = ft_substr(buf, len, BUFFER_SIZE);
			return (sub);
		}
		else if (len == BUFFER_SIZE)
		{
			tmp = buffer;
			buffer = ft_strjoin(buffer, buf);
			free(tmp);
			return (get_next_line(fd));
		}
		else
			return (NULL);
	}
	else if (nb < BUFFER_SIZE)
	{
		tmp = ft_substr(buf, 0, len);
		sub = ft_strjoin(buffer, tmp);
		free(tmp);
		return (sub);
	}
	else 
		return (NULL);
}
