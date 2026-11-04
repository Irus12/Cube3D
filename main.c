#include "include/cube.h"

/*
	TEMPORARY MAIN USED TO TEST 
*/

int	close_window(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit(0);
	return (0);
}

/*
static int	render(t_data *d, t_player *player)
{
	memset(d->addr, 0, HEIGHT * d->line_length);	//fond noir 
	put_pixel(d, player->position.x, player->position.y, 0xFFFFFF);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}
*/

/*
	MLX ne fonctionne pas comme ca, tout se fait dans une loop
	mlx_loop_hook qui a sa propre boucle 
*/
void	game(t_player player, t_data data)
{
	while (1)
	{
		draw_circle(&data, player.position, 5, 0xFFFFFF);
	}
}

int	main(void)
{
	t_data	img;
	t_player player;

	player_init(player);
	//mlx setpup
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "CUBE");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	//render
	game(player, img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	//mlx ending
	//setup_hooks(&img);
	mlx_hook(img.win, 2, 1L << 0, key_press, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_loop_hook(img.mlx, game, &player, &img);

	mlx_loop(img.mlx);
	

	return (0);
}