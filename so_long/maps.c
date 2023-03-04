/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:58:10 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/04 23:58:20 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_read(char *carte, t_game *game)
{
    int fd;
    char    *line;

    fd = open(carte,O_RDONLY);
    line = get_next_line(fd);
    if (line == NULL)
        exit(1);
    game->height = 0;
    game->weight = ft_strlen(line);
    game->str_line = ft_strdup(line);
    free(line);
    while(line)
    {
        game->height++;
        line = get_next_line(fd);
        if(line)
        {
            game->str_line = ft_strjoin(game->str_line,line);
        }
        free(line);
    }
    close(fd);
}

void    wall_surround(t_game *game)
{
    int i = 0;
    while ((size_t)i < ft_strlen(game->str_line))
    {
	    if (i < game->weight)
	    {
	    	if (game->str_line[i] != '1')
		    	print_err(" 1 : Map must be closed/surrounded by walls");
	    }
	    else if (i % game->weight == 0 || i % game->weight == game->weight - 1)
	    {
		    if (game->str_line[i] != '1')
			    print_err(" 2 : Map must be closed/surrounded by walls");
	    }
	    else if ((size_t)i > ft_strlen(game->str_line) - game->weight)
	    {
	    	if (game->str_line[i] != '1')
		    	print_err("Map must be closed/surrounded by walls");
	    }
	    i++;
    }
}

void    check_symboles(t_game *game)
{
    int sym_p = 0;
    int sym_e = 0;
    game->dooooor = 0;

    game->col_total = 0;
    game->col_count = 0;

    char *p = game->str_line;
    while(*p)
    {
        if(*p == 'P')
            sym_p++;
        else if(*p == 'C')
            game->col_total++;
        else if(*p == 'E')
        {
            sym_e++;
            game->dooooor++;
        }
        p++;
    }
    if(game->col_total == 0)
        print_err("La carte doit contenir au moins un collectible\n");
    if(sym_p < 1)
        print_err("La carte doit contenir au moins un position de départ\n");
    if(sym_e != 1)
        print_err("La carte doit avoir une une sortie \n");
}

void    validate_carte(t_game *game)
{
    if((int)ft_strlen(game->str_line) != (game->height * game->weight))
        print_err("La carte doit être rectangulaire");
    wall_surround(game);
    check_symboles(game);
    map_2d(game);
    floodFill(game->xpos, game->ypos , game->height, game->weight, game);
    if (game->col_total > 0 || game->dooooor > 0)
    {
        write(2, "Error \n", 8);
        exit(1);
    }
}