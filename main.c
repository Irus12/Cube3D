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
	MLX ne fonctionne pas comme ca, tout se fait dans une loop
	mlx_loop_hook qui a sa propre boucle 

int	game(t_data *data)
{
	ft_bzero(data->addr, HEIGHT * data->line_length); // on reset sinon on garde les ancienne frame affiché
	draw_circle(data, data->player->position, 6, 0xFFFFFF);
	draw_line(data, data->player->position, data->player->direction);
	draw_circle(data, data->player->direction, 3, 0xFF0000);
	recalulate_dir(data->player);

	mlx_put_image_to_window(data->mlx, data->win, data->data, 0, 0);
	return (0);
}
*/

int	rendering_all(t_data *data)
{
	ft_bzero(data->addr, HEIGHT * data->line_length); // on reset sinon on garde les ancienne frame affiché
	//render_world(data);
	render_player(data);
	//render_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

}

void	update_gamestate(t_data *data)
{
	update_player(data->player, t_key keys);
	//update_door();
	//update_item();
}


int game_loop(t_data *data)
{
	update_gamestate(data);
	rendering_all(data);
	return (0);
}

void	game_launch(t_data data)
{
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	//mlx_hook(data.win, 2, 1L << 0, key_release, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);

	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
}

int	main(void)
{
	t_data	data;
	t_player player;

	player_init(&player);
	data.player = &player;

	//mlx setpup
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "CUBE");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	game_launch(data);

	return (0);
}