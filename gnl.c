#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd)
{
	char	*start = malloc(10000);
	char	*cursor = start;

	while (read(fd, cursor, 1) > 0)
	{
		if (*cursor == '\n')
		{
//			free(start);
			break;
		}
		*cursor++;
	}
	if (cursor > start)
	{
		*cursor = 0;
		free(start);
		return (start);
	}
	return (NULL);
}

int	main()
{
	int	fd = open("file", O_RDONLY);
	int	i = 0;

	while (i < 6)
	{
		printf("Return : %s\n", get_next_line(fd));
		i++;
	}
	close(fd);
	system("leaks a.out");
}
