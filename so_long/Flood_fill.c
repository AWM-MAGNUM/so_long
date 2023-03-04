/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:31:22 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/04 23:55:40 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     maps_is_valid(t_game *p ,int x,int y)
{
    if( p->map_f[x][y] == '*')
        return (-1);
    return(1);   
}
void    check_coin(char **map, int x, int y, t_game *data)
{
    (void)map;
    if (data->map_f[x][y] == 'C')
        data->col_total--;
}
void    floodFill(int x,int y,int height ,int width, t_game *data)
{  
    if (y < 0 || x > height || x < 0 || y > width )
        return;
    if (data->col_total <= 0)
        return;
    if(data->map_f[x][y] == 'E')
    {
        data->dooooor--;
        return ;
    }
    if(data->map_f[x][y] == '*')
        return ;
    if(data->map_f[x][y] == '1')
        return ;
    check_coin(data->map_f, x, y, data);   
        data->map_f[x][y] = '*';   
    floodFill(x - 1, y, height, width, data); // left
    floodFill( x + 1, y, height, width, data); // right
    floodFill( x, y + 1, height, width, data); // top
    floodFill( x, y - 1, height, width, data); // bottom       
}