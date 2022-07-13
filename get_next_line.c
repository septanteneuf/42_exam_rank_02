#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

// char	*ft_strjoin(char *s, char c)
// {
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	str = (char *) malloc(i + 2);
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = c;
// 	str[i + 1] = '\0';
// 	free(s);
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	char	buf;
// 	char	*line;
// 	int		ret;
// 	int		i;

// 	if (fd < 0)
// 		return (NULL);
// 	line = ft_strdup("");
// 	while ((ret = read(fd, &buf, 1)) > 0)
// 	{
// 		line = ft_strjoin(line, buf);
// 		if (buf == '\n')
// 			break ;
// 	}
// 	i = 0;
// 	while (line[i])
// 		i++;
// 	if (i == 0)
// 	{
// 		free(line);
// 		line = NULL;
// 	}
// 	if (ret == -1)
// 	{
// 		free(line);
// 		line = NULL;
// 	}
// 	return (line);
// }

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

int main(int ac, char **av)
{
	int		fd;
	char	*line;
	(void)	ac;

	fd = open(av[1], O_RDONLY);
    while ((line = get_next_line(fd)) != 0)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
//	system("leaks a.out");
	return (0);
}