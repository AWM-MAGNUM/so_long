/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:58:41 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/04 23:58:44 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

void game_init(t_game *g, char *carte)
{
	g->mlx = mlx_init();
	g->img = img_xpm(g->mlx);
	map_read(carte, g);
	g->win = mlx_new_window(g->mlx, g->weight * 50, g->height * 50, "so_long");
	validate_carte(g);
	pix_img(g);
}
int exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int to_play(int keywords_id, t_game *game)
{
	static int walk_count;
	printf("%d\n", keywords_id);
	if (keywords_id == KEY_ESC)
		exit_game(game);
	if (keywords_id == KEY_W || keywords_id == KEY_XK_Up)
		move_player_up(game);
	if (keywords_id == KEY_A || keywords_id == KEY_XK_down)
		move_player_left(game);
	if (keywords_id == KEY_S || keywords_id == KEY_XK_left)
		move_player_down(game);
	if (keywords_id == KEY_D || keywords_id == KEY_XK_right)
		move_player_right(game);
	printf("%d\n", ++walk_count);
	return (0);
}

int main(int argc, char **argv)
{
	t_game *game;
	if (argc != 2)
		print_err("map is missing.\n");
	game = malloc(sizeof(t_game));
	game_init(game, argv[1]);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &to_play, game);
	mlx_loop(game->mlx);
	system("leaks so.long");
	return (0);
}
