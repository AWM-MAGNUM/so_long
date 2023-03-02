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
    printf("%s\n", game->str_line);
}


void    wall_surround(t_game *game)
{
    int i = 0;
    while ((size_t)i < ft_strlen(game->str_line))
    {
	    if (i < game->weight)
	    {
             printf("{%c} " ,game->str_line[i]);
	    	if (game->str_line[i] != '1')
		    	print_err(" 1 : Map must be closed/surrounded by walls");
	    }
	    else if (i % game->weight == 0 || i % game->weight == game->weight - 1)
	    {
            printf("[%c]",game->str_line[i]);
		    if (game->str_line[i] != '1')
			    print_err(" 2 : Map must be closed/surrounded by walls");
	    }
	    else if ((size_t)i > ft_strlen(game->str_line) - game->weight)
	    {
             printf("<%c> " ,game->str_line[i]);
	    	if (game->str_line[i] != '1')
		    	print_err("Map must be closed/surrounded by walls");
	    }
	    i++;
    }
}

void    check_symboles(t_game *game)
{
    int sym_p = 0;
    int sym_c = 0;
    int sym_e = 0;

    char *p = game->str_line;
    while(*p)
    {
        if(*p == 'P')
            sym_p++;
        else if(*p == 'C')
            sym_c++;
        else if(*p == 'E')
            sym_e++;
    }
    if(sym_c < 1)
        print_err("La carte doit contenir au moins un collectible\n");
    if(sym_p < 1)
        print_err("La carte doit contenir au moins un position de départ\n");
    if(sym_e == 1)
        print_err("La carte doit avoir une une sortie \n");
}

void    validate_carte(t_game *game)
{
    int i ;

    i = 0;
    while (i < game->height)
    {
        if((int)ft_strlen(game->str_line) != (game->height * game->weight))
            print_err("La carte doit être rectangulaire");
    }
           i++;
        wall_surround(game);
        check_symboles(game);
}
void	game_init(t_game *g, char *carte)
{
	g->mlx = mlx_init();
	g->img = img_xpm(g->mlx);
	map_read(carte, g);
	validate_carte(g);
	g->win = mlx_new_window(g->mlx, g-> verticale* 64, g->horizontale * 64, "so_long");
	show_img(g);
}

void    print_err(char *message)
{
    write(2,"Error\n",6);
    write(2,message,ft_strlen(message));
    exit(1);
}

int main(int argc, char **argv)
{
    t_game *game;
    if (argc != 2)
        print_err("map is missing.\n");
    game = malloc(sizeof(t_game));
    game_init(game,argv[1]);
    map_read(argv[1], game);
    mlx_loop(game->mlx);
}
