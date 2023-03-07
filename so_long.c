/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:58:41 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/07 01:14:39 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *message)
{
	write(2, "Error\n", 7);
	write(2, message, ft_strlen(message));
	exit(1);
}

void	config_game(t_game *g, char *carte)
{
	g->walk_cnt = 0;
	g->dooooor = 0;
	g->col_total = 0;
	g->col_count = 0;
	g->mlx = mlx_init();
	g->img = img_xpm(g->mlx);
	map_read(carte, g);
	g->win = mlx_new_window(g->mlx, g->weight * 50, g->height * 50, "so_long");
	validate_carte(g);
	pix_img(g);
}

int	quit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	to_play(int keywords_id, t_game *game)
{
	if (keywords_id == 15104)
		exit(1);
	if (keywords_id == KEY_ESC)
		quit_game(game);
	if (keywords_id == KEY_W || keywords_id == KEY_XK_UP)
		move_player_up(game);
	if (keywords_id == KEY_A || keywords_id == KEY_XK_DOWN)
		move_player_left(game);
	if (keywords_id == KEY_S || keywords_id == KEY_XK_LEFT)
		move_player_down(game);
	if (keywords_id == KEY_D || keywords_id == KEY_XK_RIGHT)
		move_player_right(game);
	ft_printf("%d\n", ++game->walk_cnt);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		print_err("map is missing\n");
	if (ft_strcmp(ft_strchr(argv[1], '.'), ".ber"))
	{
		write(2, "Error .ber\n", 12);
		exit(1);
	}
	game = malloc(sizeof(t_game));
	config_game(game, argv[1]);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &to_play, game);
	mlx_hook(game->win, 17, 1L << 0, &to_play, game);
	mlx_loop(game->mlx);
	system("leaks so.long");
	return (0);
}
