#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"
#include <string.h>

typedef struct s_game
{
    char    *str_line;
    int     height;
    int     weight;
    int     *g;
}  t_game;

char	*get_next_line(int fd);
int     ft_strlen(char *s);
char	*ft_strdup(const char *s1);
char	*ft_joint(char *left, char *buf);
void    map_read(char  *carte, t_game *game);
void    wall_surround(t_game *game);
void    print_err(char *message);



#endif