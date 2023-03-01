#include "so_long.h"
t_img img_xpm(void  *mlx)
{
    t_img  tty;
    
    int ver;
    int horz;

    tty.wall_img = mlx_xpm_file_to_image(mlx, "./wall.xpm",&ver,&horz);
    tty.coin_img = mlx_xpm_file_to_image(mlx, "./coin.xpm",&ver,&horz);
    tty.player_img = mlx_xpm_file_to_image(mlx, "./player.xpm",&ver,&horz);
    tty.exit_img = mlx_xpm_file_to_image(mlx, "./exit.xpm",&ver,&horz);
    tty.ground_img = mlx_xpm_file_to_image(mlx, "./ground.xpm",&ver,&horz);
    return(tty);
}

void    draw_map(t_game *g,int ligne,int colonne)
{
    char current_char = g->str_line[ligne * g->weight + colonne];

    if(current_char == '1')
        mlx_put_image_to_window(g->mlx,g->win,g->wall,colonne * 64,ligne * 64);
    else if(current_char == 'C')
        mlx_put_image_to_window(g->mlx,g->win,g->coin,colonne * 64 , ligne * 64);
    else if(current_char == 'P')
        mlx_put_image_to_window(g->mlx,g->win,g->player,colonne *64 , ligne * 64);
    else if(current_char == 'E')
        mlx_put_image_to_window(g->mlx,g->win,g->exit,colonne *64 , ligne * 64);
    else
        mlx_put_image_to_window(g->mlx,g->win,g->ground,colonne *64 , ligne * 64);
}

void    show_img(t_game *game)
{
    int verticale;
    int horizontale;

    horizontale = 0;
    while(horizontale < game->height)
    {
        verticale = 0;
        while (verticale < game->weight)
        {
            draw_map(game,verticale,horizontale);
                verticale++;
        }
        horizontale++;
    }
}
