/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:57:40 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/10 04:06:41 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	img_xpm(void *mlx)
{
	t_img	tty;
	int		v;
	int		h;

	v = 50;
	h = 50;
	tty.wall_img = mlx_xpm_file_to_image(mlx, "./Bonus/img/wall.xpm", &v, &h);
	tty.coin_img = mlx_xpm_file_to_image(mlx, "./Bonus/img/coin.xpm", &v, &h);
	tty.player_i = mlx_xpm_file_to_image(mlx, "./Bonus/img/player.xpm", &v, &h);
	tty.exit_img = mlx_xpm_file_to_image(mlx, "./Bonus/img/exit.xpm", &v, &h);
	tty.gr_img = mlx_xpm_file_to_image(mlx, "./Bonus/img/ground.xpm", &v, &h);
	tty.lune1 = mlx_xpm_file_to_image(mlx, "./Bonus/img/lune1.xmp", &v, &h);
	tty.lune2 = mlx_xpm_file_to_image(mlx, "./Bonus/img/lune2.xpm", &v, &h);
	tty.lune3 = mlx_xpm_file_to_image(mlx, "./Bonus/img/lune3.xpm", &v, &h);
	tty.lune4 = mlx_xpm_file_to_image(mlx, "./Bonus/img/lune4.xpm", &v, &h);
	tty.lune5 = mlx_xpm_file_to_image(mlx, "./Bonus/img/lune5.xpm", &v, &h);
	tty.lune6 = mlx_xpm_file_to_image(mlx, "./Bonus/img/lune6.xpm", &v, &h);
	tty.lune7 = mlx_xpm_file_to_image(mlx, "./Bonus/img/lune7.xpm", &v, &h);
	tty.lune8 = mlx_xpm_file_to_image(mlx, "./Bonus/img/lune8.xpm", &v, &h);
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
		mlx_loop_hook(g->mlx, (int (*)(void *))coin_b, g);
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
