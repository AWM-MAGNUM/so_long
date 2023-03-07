/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:58:53 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/07 01:14:39 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 5

# define KEY_ESC 53
# define KEY_X 0
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_XK_UP 126
# define KEY_XK_DOWN 123
# define KEY_XK_LEFT 125
# define KEY_XK_RIGHT 124

typedef struct s_img
{
	void	*wall_img;
	void	*gr_img;
	void	*coin_img;
	void	*player_img;
	void	*exit_img;
}			t_img;
typedef struct s_map2d
{
	int	i;
	int	n;
	int	j;
}			t_map2d;
typedef struct s_game
{
	char	*str_string;
	char	**map_f;
	int		height;
	int		weight;
	int		out;
	int		*g;
	void	*mlx;
	t_img	img;
	t_map2d	*map;
	void	*imgv;
	void	*win;
	char	*wall;
	char	*ground;
	char	*coin;
	int		dooooor;
	char	*player;
	char	*exit;
	int		x;
	int		y;
	int		col_count;
	int		col_total;
	int		col_to_m2;
	int		walk_cnt;
	int		verticale;
	int		horizontale;
	int		xpos;
	int		ypos;
	int		sym_p;
	int		sym_e;

}			t_game;

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
int			ft_strlcpy(char *dst, char *src, int len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s1);
int			ft_strcmp(char *s1, char *s2);
void		map_read(char *carte, t_game *game);
void		wall_surround(t_game *game);
void		check_symboles(t_game *game);
void		validate_carte(t_game *game);
void		config_game(t_game *g, char *carte);
void		print_err(char *message);

void		draw_map(t_game *g, int ligne, int colonne, char current_char);
void		pix_img(t_game *game);
t_img		img_xpm(void *mlx);

void		move_player_up(t_game *g);
void		move_player_down(t_game *g);
void		move_player_left(t_game *g);
void		move_player_right(t_game *g);
int			to_play(int keywords_id, t_game *game);
int			quit_game(t_game *game);

void		map_2d(t_game *game);
void		floodfill(int x, int y, t_game *data);

#endif