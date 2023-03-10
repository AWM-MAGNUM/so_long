/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   360.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:18:41 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/10 04:16:22 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	pixxx_img(t_game *game, void *ptr)
{
	int	ln;
	int	cl;
	int	y;

	ln = 0;
	cl = 0;
	y = 0;
	while (ln < game->height)
	{
		cl = 0;
		while (cl < game->weight)
		{
			if (game->str_string[y] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img.gr_img,
					cl * 50, ln * 50);
				mlx_put_image_to_window(game->mlx, game->win, ptr, cl * 50, ln
					* 50);
			}
			cl++;
			y++;
		}
		ln++;
	}
}

void	coin_b(t_game *game)

{
	static int		mask = 0;
	int				ver;
	int				horz;	

	ver = 50;
	horz = 50;
	mask++;
	if (mask == 11000)
		mask = 0;
	else if (mask == 1000)
		pixxx_img(game, game->img.lune2);
	else if (mask == 2000)
		pixxx_img(game, game->img.lune3);
	else if (mask == 4000)
		pixxx_img(game, game->img.lune4);
	else if (mask == 6000)
		pixxx_img(game, game->img.lune5);
	else if (mask == 8000)
		pixxx_img(game, game->img.lune6);
	else if (mask == 10000)
		pixxx_img(game, game->img.lune7);
}
