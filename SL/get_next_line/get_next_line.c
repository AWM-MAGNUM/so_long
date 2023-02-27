

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

char	*ft_the_reader(int fd, char *unreal)
{
	char		*buff;
	int			count_bytes;

buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
count_bytes = 1;
	while (ft_strchr(unreal, '\n') == NULL && count_bytes != 0)
	{
		count_bytes = read(fd, buff, BUFFER_SIZE);
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*mini_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	mini_line = ft_the_reader(fd, mini_line);
	if (mini_line == NULL)
		return (NULL);
	line = ft_extracteur_the_line(mini_line);
	mini_line = ft_update_42(mini_line);
	return (line);
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