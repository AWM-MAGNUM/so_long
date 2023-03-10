/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keywords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:58:25 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/10 04:06:23 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	steps_win(t_game *game)
{
	game->step++;
	ft_printf("%s %d%s\n", "Congratulations! You have won in "\
		, game->step, " steps.");
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
		g->step++;
		ft_printf("%d\n", g->step);
		pix_img(g);
	}
	g->str = ft_itoa(g->step);
	mlx_string_put(g->mlx, g->win, 10, 10, 0xFFA500, g->str);
	free(g->str);
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
		g->step++;
		ft_printf("%d\n", g->step);
		pix_img(g);
	}
	g->str = ft_itoa(g->step);
	mlx_string_put(g->mlx, g->win, 10, 10, 0x00FF00, g->str);
	free(g->str);
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
		g->step++;
		ft_printf("%d\n", g->step);
		pix_img(g);
	}
	g->str = ft_itoa(g->step);
	mlx_string_put(g->mlx, g->win, 10, 10, 0x00FFFF, g->str);
	free(g->str);
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
		g->step++;
		ft_printf("%d\n", g->step);
		pix_img(g);
	}
	g->str = ft_itoa(g->step);
	mlx_string_put(g->mlx, g->win, 10, 10, 0xFF00FF, g->str);
	free(g->str);
}
