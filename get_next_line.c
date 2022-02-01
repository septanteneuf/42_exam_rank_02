/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:58:30 by 0xNino            #+#    #+#             */
/*   Updated: 2022/01/03 16:00:59 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*ft_strjoin(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = (char *) malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	char	buf;
	char	*line;
	int		ret;
	int		i;

	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	while ((ret = read(fd, &buf, 1)) > 0)
	{
		line = ft_strjoin(line, buf);
		if (buf == '\n')
			break ;
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0)
	{
		free(line);
		line = NULL;
	}
	if (ret == -1)
	{
		free(line);
		line = NULL;
	}
	return (line);
}
