/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:58:10 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/08 01:08:44 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(char *carte, t_game *game)
{
	int		fd;
	char	*string;

	fd = open(carte, O_RDONLY);
	if (fd < -1)
		exit(0);
	string = get_next_line(fd);
	if (string == NULL)
		exit(1);
	game->height = 0;
	game->weight = ft_strlen(string);
	game->str_string = ft_strdup(string);
	free(string);
	while (string)
	{
		game->height++;
		string = get_next_line(fd);
		if (string)
		{
			game->str_string = ft_strjoin(game->str_string, string);
		}
		free(string);
	}
	close(fd);
}

void	wall_surround(t_game *game)
{
	int	i;

	i = 0;
	while ((size_t)i < ft_strlen(game->str_string))
	{
		if (i < game->weight)
		{
			if (game->str_string[i] != '1')
				print_err("1 : La carte doit être fermée/entourée de murs");
		}
		else if (i % game->weight == 0 || i % game->weight == game->weight - 1)
		{
			if (game->str_string[i] != '1')
				print_err("2 : La carte doit être fermée/entourée de murs");
		}
		else if ((size_t)i > ft_strlen(game->str_string) - game->weight)
		{
			if (game->str_string[i] != '1')
				print_err("3 : La carte doit être fermée/entourée de murs");
		}
		i++;
	}
}

void	check_symboles(t_game *game)
{
	int		i;

	game->sym_p = 0;
	game->sym_e = 0;
	i = 0;
	while (game->str_string[i])
	{
		if (game->str_string[i] == 'P')
			game->sym_p++;
		else if (game->str_string[i] == 'C')
			game->col_total++;
		else if (game->str_string[i] == 'E')
		{
			game->sym_e++;
			game->dooooor++;
		}
		i++;
	}
	if (game->col_total == 0)
		print_err("La carte doit contenir au moins un collectible\n");
	if (game->sym_p < 1)
		print_err("La carte doit contenir au moins un position de départ\n");
	if (game->sym_e != 1)
		print_err("La carte doit avoir une une sortie \n");
}

void	validate_carte(t_game *game)
{
	if (((int)ft_strlen(game->str_string)) != (game->height * game->weight))
		print_err("La carte doit être rectangulaire");
	wall_surround(game);
	check_symboles(game);
	map_2d(game);
	game->col_to_m2 = game->col_total;
	floodfill(game->xpos, game->ypos, game);
	if (game->col_to_m2 > 0 || game->dooooor > 0)
	{
		write(2, "Error!!!\n", 10);
		exit(1);
	}
}
