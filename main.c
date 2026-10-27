#include "include/cube.h"

/*
	TEMPORARY MAIN USED TO TEST 
*/


static void	put_pixel(t_data *d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	close_window(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit(0);
	return (0);
}


static int	render(t_data *d)
{
	memset(d->addr, 0, HEIGHT * d->line_length);	/* fond noir */
	put_pixel(d, d->x, d->y, 0xFFFFFF);			/* le pixel blanc */
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	d;

	d.mlx = mlx_init();
	if (!d.mlx)
		return (1);
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "pixel");
	d.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length, &d.endian);
	d.x = WIDTH / 2;
	d.y = HEIGHT / 2;
	mlx_hook(d.win, 2, 1L << 0, key_press, &d);		/* KeyPress */
	mlx_hook(d.win, 17, 0, close_window, &d);		/* croix de la fenêtre */
	mlx_loop_hook(d.mlx, render, &d);
	mlx_loop(d.mlx);
	return (0);
}