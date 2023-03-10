/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:31:22 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/10 04:05:55 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	maps_is_valid(t_game *p, int x, int y)
{
	if (p->map_f[x][y] == '*')
		return (-1);
	return (1);
}

void	check_coin(char **map, int x, int y, t_game *data)
{
	(void)map;
	if (data->map_f[x][y] == 'C')
		data->col_to_m2--;
}

void	floodfill(int x, int y, t_game *data)
{
	if (y < 0 || x > data->height || x < 0 || y > data->weight)
		return ;
	if (data->col_to_m2 < 0)
		return ;
	if (data->map_f[x][y] == 'E')
	{
		data->dooooor--;
		return ;
	}
	if (data->map_f[x][y] == '*')
		return ;
	if (data->map_f[x][y] == '1')
		return ;
	check_coin(data->map_f, x, y, data);
	data->map_f[x][y] = '*';
	floodfill(x - 1, y, data);
	floodfill(x + 1, y, data);
	floodfill(x, y + 1, data);
	floodfill(x, y - 1, data);
}
