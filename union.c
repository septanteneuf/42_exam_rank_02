/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:04:37 by 0xNino            #+#    #+#             */
/*   Updated: 2022/05/27 11:10:01 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	used[255];
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!used[(unsigned char)argv[i][j]])
				{
					write(1, &argv[i][j], 1);
					used[(unsigned char)argv[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// void	ft_union(const char *s1, const char *s2)
// {
// 	char	checkalpha[127];
// 	int		i;
// 	int		j;
	
// 	if (s1 && s2)
// 	{
// 		i = 0;
// 		while (i < 127)
// 		{
// 			checkalpha[i] = 0;
// 		   i++;
// 		}
// 		i = 0;
// 		while (s1[i] != 0)
// 		{
// 			j =	s1[i];
// 			if (checkalpha[j] == 0)
// 			{
// 				write(1, &s1[i], 1);
// 				checkalpha[j] = 1;
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		while (s2[i] != 0)
// 		{
// 			j = s2[i];
// 			if (checkalpha[j] == 0)
// 			{
// 				write(1, &s2[i], 1);
// 				checkalpha[j]= 1;
// 			}
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// }