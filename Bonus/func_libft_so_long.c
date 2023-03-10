/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_libft_so_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:03:02 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/10 04:06:10 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_wolf(int k, int i, long nb)
{
	char	*str;

	str = NULL;
	if (nb < 0)
		str = malloc(sizeof(char) * (i + 2));
	else
		str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (k > 0)
	{
		if (nb < 0)
		{
			str[0] = '-';
			i = 1;
			nb *= -1;
		}
			str[i] = ((nb / k) + 48);
			nb -= ((nb / k) * k);
			k /= 10;
			i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		k;
	int		i;
	long	tmp;
	long	nb;

	i = 1;
	k = 1;
	nb = n;
	tmp = nb;
	if (tmp < 0)
		tmp *= -1;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		k *= 10;
		i++;
	}
	return (ft_wolf(k, i, nb));
}
