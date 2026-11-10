/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:57:58 by romeo             #+#    #+#             */
/*   Updated: 2026/11/10 15:50:05 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	init_map_lines(t_map *map)
{
	int	i;

	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (1);
	i = 0;
	while (i <= map->height)
		map->map[i++] = NULL;
	return (0);
}

int	read_map(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	if (init_map_lines(map))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), 1);
		map->map[i++] = line;
	}
	return (close(fd) < 0);
}
