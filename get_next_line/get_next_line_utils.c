/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:06 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/02 04:17:48 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenn(char *s)
{
	int			i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int			i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t			i;
	size_t			j;
	char			*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}
// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*new_mem;
// 	size_t	s1_len;
// 	size_t	s2_len;

// 	new_mem = NULL;
// 	if (s1 == NULL && s2 == NULL)
// 		return (NULL);
// 	else if (s1 == NULL)
// 		return (ft_strdup(s2));
// 	else if (s2 == NULL)
// 		return (ft_strdup(s1));
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	new_mem = malloc(s1_len + s2_len);
// 	if (!(new_mem))
// 		return (NULL);
// 	ft_strlcpy(new_mem, s1, s1_len + 1);
// 	ft_strlcpy(new_mem + s1_len, s2, s2_len + 1);
// 	free(s1);
// 	free(s2);
// 	return (new_mem);
// }

// char	*ft_strdup(char *s)
// {
// 	char	*new_mem;
// 	int		size;
// 	int		i;

// 	new_mem = NULL;
// 	size = ft_strlen(s);
// 	i = 0;
// 	new_mem = malloc(size + 1);
// 	if (!(new_mem))
// 		return (NULL);
// 	while (s[i] && s[i] != '\n')
// 	{
// 		new_mem[i] = s[i];
// 		i++;
// 	}
// 	new_mem[i] = '\0';
// 	return (new_mem);
// }

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc (sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlcpy(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
	{
		return (src_len);
	}
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*ft_extracteur_the_line(char *BIG_LINE)
{
	char		*str;
	int			i;

	i = 0;
	if (BIG_LINE[i] == '\0')
		return (NULL);
	while (BIG_LINE[i] != '\0' && BIG_LINE[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (BIG_LINE[i] != '\0' && BIG_LINE[i] != '\n')
	{
		str[i] = BIG_LINE[i];
		i++;
	}
	if (BIG_LINE[i] == '\n')
	{
		str[i] = BIG_LINE[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_update_42(char *META)
{
	int			i;
	int			k;
	char		*btr;

	i = 0;
	while (META[i] && META[i] != '\n')
		i++;
	if (META[i] == '\0')
	{
		free(META);
		return (NULL);
	}
	btr = (char *)malloc(sizeof(char) * (ft_strlen(META) - i + 1));
	if (!btr)
		return (NULL);
	i++;
	k = 0;
	while (META[i] != '\0')
		btr[k++] = META[i++];
	btr[k] = '\0';
	free(META);
	return (btr);
}
