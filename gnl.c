#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i;
 
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	a[i] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\n')
			break;
		i++;
	}
	if (!a[0])
		return (NULL);
	new_a = malloc(i + 1);
	if (!new_a)
		return (NULL);
	i = 0;
	while (a[i])
	{
		new_a[i] = a[i];
		i++;
	}
	new_a[i] = '\0';
	return (new_a);
}

int main()
{
    int fd = open("file", O_RDONLY);
    int i = 0;
    while (i < 6)
    {
        printf("Return : %s\n", get_next_line(fd));
        i++;
    }
    
}

// int main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	(void)	argc;

// 	fd = open(argv[1], O_RDONLY);
//     while ((line = get_next_line(fd)) != 0)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// //	system("leaks a.out");
// 	return (0);
// }
