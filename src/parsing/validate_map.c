/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 19:01:42 by romeo             #+#    #+#             */
/*   Updated: 2026/11/10 14:46:29 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// Renvoie le type de la case (y, x), 
// ou ' ' si elle est hors de la grille ou après la fin de la ligne
static char	get_cell(t_map *map, int y, int x)
{
	if (y < 0 || y >= map->height || x < 0)
		return (' ');
	if (x >= (int)ft_strlen(map->map[y]))
		return (' ');
	return (map->map[y][x]);
}

static int	touches_void(t_map *map, int y, int x)
{
	return (get_cell(map, y - 1, x) == ' '
		|| get_cell(map, y + 1, x) == ' '
		|| get_cell(map, y, x - 1) == ' '
		|| get_cell(map, y, x + 1) == ' ');
}

static int	check_closed(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '0' && touches_void(map, y, x))
				return (print_error("Map is not closed"));
		}
	}
	return (0);
}

//la map a ete charge, voyons si elle est valide
int	validate_map(t_game *game)
{
	if (check_chars(game) != 0)
		return (1);
	return (check_closed(&game->map));
}
