/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:35:02 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/11 17:23:59 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cube.h"

double	absv(double i)
{
	if (i < 0)
		return (-i);
	return (i);
}

t_point new_point(double x, double y)
{
	t_point out;
	out.x = x;
	out.y = y;
	return (out);
}

/**
 * @brief Takes an ingame coordinate and returns it's equivalant position in the t_map array
 * 
 */
t_point	ingame_to_map_position(t_point *point)
{
	int x;
	int y;

	x = point->x * TILE_TO_MAP_FACTOR;
	y = point->y * TILE_TO_MAP_FACTOR;
	return (new_point(x,y));
}

/**
 * @brief receives a ingame coordinate and will returns
 * it's equivalant char value in the t_map array.
 * 
 */
char	map_zone_check(t_point *point, t_map *map)
{
	t_point map_coord;
	
	map_coord = ingame_to_map_position(point);
	return (map->map[(int)map_coord.y][(int)map_coord.x]);
}
