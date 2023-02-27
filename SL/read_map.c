#include "so_long.h"

void    map_read(char *carte, t_game *game)
{
    int fd;
    char    *line;

    fd = open(carte,O_RDONLY);
    line = get_next_line(fd);
    game->height = 0;
    game->weight = ft_strlen(line) - 1;
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
    }
    close(fd);
    printf("%s\n", game->str_line);
}

void    wall_surround(t_game *game)
{
    int i = 0;

    while(i < ft_strlen(game->str_line))
    {
        if(i < game->weight)
        {
            if(game->str_line[i] != 1)
                print_err("La carte doit être fermée/entourée de murs(1)");
        }
        else if(i % game->weight == 0 || i % game->weight == game->weight -1)
        {
            if(game->str_line[i] != '1')
                print_err("La carte doit être fermée/entourée de murs(1)");
        }
        else if(i > ft_strlen(game->str_line) - game->weight)
        {
            if(game->str_line[i] != '1')
                print_err("La carte doit être fermée/entourée de murs(1)");
        }
        i++;
    }
}
void    print_err(char *message)
{
    write(2,"Error\n",6);
    write(2,message,ft_strlen(message));
    exit(1);
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc == 2)
    {
            //print_err("map id non valide");
        map_read(argv[1], &game);
    }
}
