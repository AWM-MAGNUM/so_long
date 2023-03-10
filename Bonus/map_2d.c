/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 02:21:27 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/10 04:06:17 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_postion(t_game *game, int j, int n, int i)
{
	if (game->str_string[j] == 'P')
	{
		game->xpos = n;
		game->ypos = i;
	}
}

void	map_2d(t_game *game)
{
	t_map2d	m;

	m.j = -1;
	m.n = 0;
	game->map_f = malloc(sizeof(char *) * (game->height + 1));
	while (game->height > m.n)
	{
		game->map_f[m.n] = malloc(sizeof(char) * (game->weight + 1));
		m.i = -1;
		while (++m.i < game->weight)
		{
			if (game->str_string[++m.j] != '1' && game->str_string[m.j] != '0'
				&& game->str_string[m.j] != 'P' && game->str_string[m.j] != 'C'
				&& game->str_string[m.j] != 'E' && game->str_string[m.j])
			{
				print_err("il y a un caractere qui n'est pas eligible");
				exit(1);
			}
			player_postion(game, m.j, m.n, m.i);
			game->map_f[m.n][m.i] = game->str_string[m.j];
		}
		game->map_f[m.n][m.i] = '\0';
		m.n++;
	}
	game->map_f[m.n] = NULL;
}
