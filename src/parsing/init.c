/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:53:36 by romeo             #+#    #+#             */
/*   Updated: 2026/10/27 18:11:44 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->x = 0;
	data->y = 0;
}

static void	init_colors(t_color_data *colors)
{
	colors->sky_r = 0;
	colors->sky_g = 0;
	colors->sky_b = 0;
	colors->floor_r = 0;
	colors->floor_g = 0;
	colors->floor_b = 0;
}

static void	init_map(t_map *map)
{
	map->textures = NULL;
	init_colors(&map->colors);
	map->map = NULL;
	map->path = NULL;
	map->height = 0;
	map->width = 0;
}

static void	init_player(t_player *player)
{
	player->position.x = 0.0;
	player->position.y = 0.0;
}

void	init_structs(t_data *data, t_map *map, t_player *player)
{
	init_data(data);
	init_map(map);
	init_player(player);
}
