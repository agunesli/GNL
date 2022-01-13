#include "get_next_line.h"

int	ft_is_line(char	*buf)
{
	int	len;

	len = 0;
	while (buf[len] && buf[len]!= '\n')
		len++;
	return (len);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buf;
	char		*tmp;
	char		*sub;
	int			nb;

	buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nb = read(fd, buf, BUFFER_SIZE);
	len = ft_is_line(buf);
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
			return (get_next_line(fg));
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
