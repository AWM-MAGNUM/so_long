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

void    draw_map(t_game *g,int ligne,int colonne, char current_char)
{
    if(current_char == '1')
        mlx_put_image_to_window(g->mlx,g->win,g->img.wall_img,colonne * 50,ligne * 50);
    else if(current_char == 'C')
    {
        mlx_put_image_to_window(g->mlx,g->win,g->img.ground_img,colonne * 50 , ligne * 50);
        mlx_put_image_to_window(g->mlx,g->win,g->img.coin_img,colonne * 50 , ligne * 50);
    }
    else if(current_char == 'P')
    {
        mlx_put_image_to_window(g->mlx,g->win,g->img.ground_img,colonne * 50 , ligne * 50);
        mlx_put_image_to_window(g->mlx,g->win,g->img.player_img,colonne * 50 , ligne * 50);
    }
    else if(current_char == 'E')
    {
        mlx_put_image_to_window(g->mlx,g->win,g->img.ground_img,colonne * 50 , ligne * 50);
        mlx_put_image_to_window(g->mlx,g->win,g->img.exit_img,colonne * 50 , ligne * 50);
    }
    else
        mlx_put_image_to_window(g->mlx,g->win,g->img.ground_img,colonne *50 , ligne * 50);
}

void    show_img(t_game *game)
{
    int i, x, y = 0;
    i = 0;
    while(i < game->height)
    {
        x = 0;
        while(x < game->weight)
        {
            draw_map(game, i, x, game->str_line[y]);
            x++;
            y++;
        }
        i++;
    }
}
