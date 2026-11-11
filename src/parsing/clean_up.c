/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:27:41 by romeo             #+#    #+#             */
/*   Updated: 2026/11/11 17:16:59 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static void	free_mlx(t_data *d)
{
	int	i;

	if (!d->mlx)
		return ;
	i = -1;
	while (++i < 4)
		if (d->game->map.textures[i].img)
			mlx_destroy_image(d->mlx, d->game->map.textures[i].img);
	if (d->img)
		mlx_destroy_image(d->mlx, d->img);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(map->textures[i].path);
		map->textures[i].path = NULL;
		i++;
	}
	free_tab(map->map);
	map->map = NULL;
}

void	free_all(t_data *data)
{
	free_mlx(data);
	free_map(&data->game->map);
}

void	error_exit(t_data *data, char *msg)
{
	if (msg)
		print_error(msg);
	free_all(data);
	exit(EXIT_FAILURE);
}
