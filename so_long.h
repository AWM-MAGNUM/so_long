#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"
#include <string.h>

typedef struct s_img {
    void    *wall_img;
    void    *ground_img;
    void    *coin_img;
    void    *player_img;
    void    *exit_img;
}                       t_img;

typedef struct s_game
{
    char    *str_line;
    int     height;
    int     weight;
    int     *g;
    void    *mlx;
    t_img   img;
    void    *imgv;
    void    *win;
    char    *wall;
    char    *ground;
    char    *coin;
    char    *player;
    char    *exit;
    int     x;
    int     y;
    int     verticale;
    int     horizontale;
   

}  t_game;

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
int     ft_strlcpy(char *dst, char *src, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void    map_read(char  *carte, t_game *game);
void    wall_surround(t_game *game);
void    check_symboles(t_game *game);
void    validate_carte(t_game *game);
void	game_init(t_game *g, char *carte);
void    print_err(char *message);

void    draw_map(t_game *g,int ligne,int colonne);
void    show_img(t_game *game);

t_img   img_xpm(void  *mlx);

#endif