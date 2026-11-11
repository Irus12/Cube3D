/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:58:36 by romeo             #+#    #+#             */
/*   Updated: 2026/10/28 16:58:47 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cube.h"

int	count_lines(char *path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
		return (-1);
	return (count);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->map)
		return ;
	i = 0;
	while (map->map[i])
		free(map->map[i++]);
	free(map->map);
	map->map = NULL;
}
