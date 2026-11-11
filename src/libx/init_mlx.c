/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:54:26 by romeo             #+#    #+#             */
/*   Updated: 2026/11/11 17:17:39 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// Charge un .xpm en image MLX et récupère l'accès à ses pixels
static int	load_texture(void *mlx, t_texture *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx, tex->path,
			&tex->width, &tex->height);
	if (!tex->img)
		return (print_error("Invalid texture file"));
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (print_error("Cannot access texture pixels"));
	return (0);
}

// Charge les 4 textures NO, SO, WE, EA
static int	load_textures(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (load_texture(d->mlx, &d->game->map.textures[i]))
			return (1);
	}
	return (0);
}

// Ouvre la fenêtre du jeu
static int	create_window(t_data *d)
{
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "cub3D");
	if (!d->win)
		return (print_error("Window creation failed"));
	return (0);
}

// Crée l'image de rendu dans laquelle chaque frame sera dessinée
static int	create_image(t_data *d)
{
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	if (!d->img)
		return (print_error("Image creation failed"));
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel,
			&d->line_length, &d->endian);
	if (!d->addr)
		return (print_error("Cannot access image pixels"));
	return (0);
}

// Lance la MLX puis enchaîne textures, fenêtre et image
int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (print_error("mlx_init failed"));
	if (load_textures(data))
		return (1);
	if (create_window(data))
		return (1);
	if (create_image(data))
		return (1);
	return (0);
}
