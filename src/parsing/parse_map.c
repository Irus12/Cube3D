/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:00:13 by romeo             #+#    #+#             */
/*   Updated: 2026/11/05 18:18:25 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	is_empty_line(char *line)
{
	while (*line == ' ')
		line++;
	return (*line == '\0');
}

// Permet de stocker les textures path dans 
// dispatch_elements puis de les skip pour parse la map
static int	parse_elements(char **lines, t_map *map)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (lines[i] && found < 6)
	{
		if (!is_empty_line(lines[i]))
		{
			if (dispatch_element(lines[i], map))
				return (-1);
			found++;
		}
		i++;
	}
	if (found < 6)
	{
		print_error("Missing element");
		return (-1);
	}
	while (lines[i] && is_empty_line(lines[i]))
		i++;
	return (i);
}

//first counting the right height for the map
//then allocating + filling the map
static int	copy_map(char **lines, t_map *map)
{
	int	i;

	while (lines[map->height])
		map->height++;
	while (map->height > 0 && is_empty_line(lines[map->height - 1]))
		map->height--;
	if (map->height == 0)
		return (print_error("Missing map"));
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
		return (print_error("Malloc failed"));
	i = -1;
	while (++i < map->height)
	{
		if (is_empty_line(lines[i]))
			return (print_error("Empty line in map"));
		map->map[i] = ft_strdup(lines[i]);
		if (!map->map[i])
			return (print_error("Malloc failed"));
		if ((int)ft_strlen(lines[i]) > map->width)
			map->width = ft_strlen(lines[i]);
	}
	return (0);
}

int	parse_map(char *path, t_game *game)
{
	char	**lines;
	int		start;

	lines = read_file(path);
	if (!lines)
		return (print_error("Cannot read map file"));
	start = parse_elements(lines, &game->map);
	if (start < 0 || copy_map(lines + start, &game->map))
	{
		free_tab(lines);
		return (1);
	}
	free_tab(lines);
	return (0);
}
