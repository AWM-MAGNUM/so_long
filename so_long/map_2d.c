# include "so_long.h"

void map_2d(t_game *game)
{
	game->map_f = malloc(sizeof(char *) * (game->height + 1));
	int n = 0;
	int i = 0;
	int j = 0;
	while (game->height > n)
	{
		game->map_f[n] = malloc(sizeof(char) * (game->weight + 1));
		i = 0;
		while (i < game->weight)
		{
			if(game->str_line[j] == 'P')
			{
				game->xpos = n;
				game->ypos = i;
			}
			game->map_f[n][i] = game->str_line[j];
			i++;
			j++;
		}
		game->map_f[n][i] = '\0';	
		n++;
	}
	game->map_f[n] = NULL;
	n = 0;
	// while (game->height > n)
	// {
	// 	printf("%s\n", game->map_f[n]);
	// 	n++;
	// }
}