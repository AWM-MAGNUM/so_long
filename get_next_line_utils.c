/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:06 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/06 02:32:13 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
