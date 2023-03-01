void	put_img(t_game *g, int colonne, int ligne)
{
	if (g->str_line[ligne * g->wid + colonne] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, colonne * 64, ligne * 64);
	}
	else if (g->str_line[ligne * g->wid + colonne] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chest, colonne * 64, ligne * 64);
	}
	else if (g->str_line[ligne  * g->wid + colonne] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chara, colonne * 64, ligne * 64);
	}
	else if (g->str_line[ligne * g->wid + colonne] == 'E' && g->all_col == g->col_cnt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.rune2, colonne * 64, ligne * 64);
	}
	else if (g->str_line[ligne * g->wid + colonne] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.rune, colonne * 64, ligne * 64);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.land, colonne * 64, ligne * 64);
	}
}