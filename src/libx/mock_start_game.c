#include "../../include/cube.h"

// Écrit un pixel de couleur dans l'image de rendu
static void	put_pixel(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Remplit la moitié haute avec C (plafond) et la moitié basse avec F (sol)
static void	draw_background(t_game *game)
{
	int	*c;
	int	color;
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		if (y < HEIGHT / 2)
			c = game->map.colors.sky;
		else
			c = game->map.colors.floor;
		color = (c[0] << 16) | (c[1] << 8) | c[2];
		x = -1;
		while (++x < WIDTH)
			put_pixel(&game->data, x, y, color);
	}
}

// Libère tout et quitte proprement (croix rouge ou ESC)
static int	close_game(t_game *game)
{
	free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}

// Gestion des touches : seulement ESC pour le mock
static int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}

// Mock : affiche fond + textures, branche ESC et la croix, lance la boucle
int	start_game(t_game *game)
{
	t_data	*d;
	int		i;

	d = &game->data;
	draw_background(game);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	i = -1;
	while (++i < 4)
		mlx_put_image_to_window(d->mlx, d->win,
			game->map.textures[i].img, 10 + i * 74, 10);
	mlx_hook(d->win, 2, 1L << 0, key_press, game);
	mlx_hook(d->win, 17, 0, close_game, game);
	mlx_loop(d->mlx);
	return (0);
}