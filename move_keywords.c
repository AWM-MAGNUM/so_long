/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keywords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:58:25 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/07 01:05:50 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	steps_win(t_game *game)
{
	game->walk_cnt++;
	ft_printf("%s %d%s\n", "Congratulations! You have won in "\
		, game->walk_cnt, " steps.");
	exit(0);
}

void	move_player_up(t_game *g)
{
	int	i;

	i = 0;
	while (g->str_string[i] != 'P' && i < (int)ft_strlen(g->str_string))
		i++;
	if (g->str_string[i - g->weight] == 'C')
		g->col_count++;
	if (g->str_string[i - g->weight] == 'E' && g->col_total == g->col_count)
		steps_win(g);
	else if (g->str_string[i - g->weight] != '1' && g->str_string[i
			- g->weight] != 'E')
	{
		g->str_string[i] = '0';
		g->str_string[i - g->weight] = 'P';
		pix_img(g);
	}
}

void	move_player_down(t_game *g)
{
	int	i;

	i = 0;
	while (g->str_string[i] != 'P' && i < (int)ft_strlen(g->str_string))
		i++;
	if (g->str_string[i + g->weight] == 'C')
		g->col_count++;
	if (g->str_string[i + g->weight] == 'E' && g->col_total == g->col_count)
		steps_win(g);
	else if (g->str_string[i + g->weight] != '1' && g->str_string[i
			+ g->weight] != 'E')
	{
		g->str_string[i] = '0';
		g->str_string[i + g->weight] = 'P';
		pix_img(g);
	}
}

void	move_player_right(t_game *g)
{
	int	i;

	i = 0;
	while (g->str_string[i] != 'P' && i < (int)ft_strlen(g->str_string))
		i++;
	if (g->str_string[i + 1] == 'C')
		g->col_count++;
	if (g->str_string[i + 1] == 'E' && g->col_total == g->col_count)
		steps_win(g);
	else if (g->str_string[i + 1] != '1' && g->str_string[i + 1] != 'E')
	{
		g->str_string[i] = '0';
		g->str_string[i + 1] = 'P';
		pix_img(g);
	}
}

void	move_player_left(t_game *g)
{
	int	i;

	i = 0;
	while (g->str_string[i] != 'P' && i < (int)ft_strlen(g->str_string))
		i++;
	if (g->str_string[i - 1] == 'C')
		g->col_count++;
	if (g->str_string[i - 1] == 'E' && g->col_total == g->col_count)
		steps_win(g);
	else if (g->str_string[i - 1] != '1' && g->str_string[i - 1] != 'E')
	{
		g->str_string[i] = '0';
		g->str_string[i - 1] = 'P';
		pix_img(g);
	}
}
