#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int ac, char **ag)
{
	(void)ac;
	(void)ag;
	int fd = open("text.txt", O_RDONLY);
	char *line;
//	size_t	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		write(1, line, ft_strlen(line));
	//	printf("%s",line);
		free(line);
		line = get_next_line(fd);
		write(1, line, ft_strlen(line));
	
	}
	return 0;
}
