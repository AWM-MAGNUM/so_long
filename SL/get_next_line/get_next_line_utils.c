/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:06 by bel-kase          #+#    #+#             */
/*   Updated: 2023/02/26 20:06:04 by bel-kase         ###   ########.fr       */
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
