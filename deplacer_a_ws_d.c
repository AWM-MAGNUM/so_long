#include "so_long.h"

int	clear_game(t_game *game)
{
	game->walk_cnt++;
	printf("%s %d%s\n", "Congratulations! You have", game->walk_cnt, "steps.");
	exit(0);
}

void	move_player_up(t_game *g)
{
	int	i;

	i = 0;  
    while (g->str_line[i] != 'P' && i < (int)ft_strlen(g->str_line))
        i++;
	if (g->str_line[i - g->weight] == 'C')
		g->col_count++;
	if (g->str_line[i - g->weight] == 'E' && g->col_total == g->col_count)
		clear_game(g);
	else if (g->str_line[i - g->weight] != '1' && g->str_line[i - g->weight] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->weight] = 'P';
		show_img(g);
	}
}

void move_player_down(t_game *g)
{
	int	i;

	i = 0;
    while (g->str_line[i] != 'P' && i < (int)ft_strlen(g->str_line))
        i++;
	if (g->str_line[i + g->weight] == 'C')
		g->col_count++;
	if (g->str_line[i + g->weight] == 'E' && g->col_total == g->col_count)
		clear_game(g);
	else if (g->str_line[i + g->weight] != '1' && g->str_line[i + g->weight] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->weight] = 'P';
		show_img(g);
	}
}

void move_player_right(t_game *g) 
{
   int i ;

   i = 0;
   while(g->str_line[i] != 'P' && i < (int)ft_strlen(g->str_line))
        i++;
    if(g->str_line[i + 1] == 'C')
        g->col_count++;
    if(g->str_line[i + 1] == 'E' && g->col_total == g->col_count)
        clear_game(g);
    else if(g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
    {
        g->str_line[i] = '0';
        g->str_line[i + 1] = 'P';
        show_img(g);
    }
}

void move_player_left(t_game *g)
{
    int i ;
    
    i = 0;
    while(g->str_line[i] != 'P' && i < (int)ft_strlen(g->str_line))
        i++;
    if(g->str_line[i - 1] == 'C')
        g->col_count++;
    if(g->str_line[i - 1] == 'E' && g->col_total == g->col_count)
        clear_game(g);
    else if(g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
    {
        g->str_line[i] = '0';
        g->str_line[i - 1] = 'P';
        show_img(g);
    }
}
  