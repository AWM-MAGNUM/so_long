/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:57:40 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/10 04:03:25 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_xpm(void *mlx)
{
	t_img	tty;
	int		ver;
	int		horz;

	ver = 50;
	horz = 50;
	tty.wall_img = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &ver, &horz);
	tty.coin_img = mlx_xpm_file_to_image(mlx, "./img/coin.xpm", &ver, &horz);
	tty.player_i = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &ver, &horz);
	tty.exit_img = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &ver, &horz);
	tty.gr_img = mlx_xpm_file_to_image(mlx, "./img/ground.xpm", &ver, &horz);
	return (tty);
}

void	draw_map(t_game *g, int l, int c, char current_char)
{
	if (current_char == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall_img, c * 50,
			l * 50);
	else if (current_char == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.gr_img, c * 50, l * 50);
		mlx_put_image_to_window(g->mlx, g->win, g->img.coin_img, c * 50,
			l * 50);
	}
	else if (current_char == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.gr_img, c * 50, l * 50);
		mlx_put_image_to_window(g->mlx, g->win, g->img.player_i, c * 50,
			l * 50);
	}
	else if (current_char == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.gr_img, c * 50, l * 50);
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit_img, c * 50,
			l * 50);
	}
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.gr_img, c * 50, l * 50);
}

void	pix_img(t_game *game)
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
			draw_map(game, ln, cl, game->str_string[y]);
			cl++;
			y++;
		}
		ln++;
	}
}
