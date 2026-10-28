/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:00:13 by romeo             #+#    #+#             */
/*   Updated: 2026/10/28 18:21:12 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	parse_map(char *path, t_map *map)
{
	map->height = count_lines(path);
	if (map->height <= 0)
		return (1);
	if (read_map(path, map))
	{
		free_map(map);
		return (1);
	}
	return (0);
}
