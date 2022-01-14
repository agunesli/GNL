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

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *dst;
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

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *dst;
        size_t  i;
        size_t  j;

        if (!s1)
                return ((char *)s2);
        if (!s2)
                return ((char *)s1);
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
