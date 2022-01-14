#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
		size_t  cpt;

		if (!s)
				return (0);
		cpt = 0;
		while (s[cpt])
				cpt++;
		return (cpt);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
		char	*dst;
		size_t  i;

		if (!s)
				return (NULL);
		if (start >= ft_strlen(s))
		{
				dst = (char *)malloc(0);
				dst[0] = '\0';
				return (dst);
		}
		if (ft_strlen(s) < len)
				len = ft_strlen(s);
		dst = (char *)malloc(sizeof(char) * (len + 1));
		if (!dst)
				return (NULL);
		i = 0;
		while (s[i + start] && i < len)
		{
				dst[i] = s[start + i];
				i++;
		}
		dst[i] = '\0';
		return (dst);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!src)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
		char	*dst;
		size_t  i;
		size_t  j;

		if (!s1)
				return (ft_strdup(s2));
		if (!s2)
				return (ft_strdup(s1));
		dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!dst)
				return (NULL);
		i = -1;
		while (s1[++i])
				dst[i] = s1[i];
		j = -1;
		while (s2[++j])
		{
				dst[i] = s2[j];
				i++;
		}
		dst[i] = '\0';
		return (dst);
}
