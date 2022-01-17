#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	int fd = open("text4.txt", O_RDONLY);
	size_t i = 0;
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s",line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	printf("nb de ligne %lu\n", i);
	return 0;
}
