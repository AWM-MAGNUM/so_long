/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:44:59 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/03 21:45:00 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

char	*ft_the_reader(int fd, char *unreal)
{
	char		*buff;
	int			count_bytes;

buff = malloc((1 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
count_bytes = 1;
	while (ft_strchr(unreal, '\n') == NULL && count_bytes != 0)
	{
		count_bytes = read(fd, buff, 1);
		if (count_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
	buff[count_bytes] = '\0';
		unreal = ft_strjoin(unreal, buff);
	}
	free(buff);
	return (unreal);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		return (ft_strdup(s + start));
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	free((char *)s);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*mini_line;

	if (fd < 0)
		return (0);
	mini_line = ft_the_reader(fd, mini_line);
	if (mini_line == NULL)
		return (NULL);
	line = ft_extracteur_the_line(mini_line);
	mini_line = ft_update_42(mini_line);
	return (ft_substr(line, 0, ft_strlen(line) - 1));
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/