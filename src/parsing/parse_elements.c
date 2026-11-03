/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 02:19:46 by romeo             #+#    #+#             */
/*   Updated: 2026/10/30 02:21:33 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	set_texture(t_texture *tex, char *s)
{
	int	fd;

	if (tex->path)
		return (print_error("Duplicate texture"));
	tex->path = ft_strtrim(s, " ");
	if (!tex->path)
		return (print_error("Malloc failed"));
	fd = open(tex->path, O_RDONLY);
	if (fd < 0)
		return (print_error("Cannot open texture"));
	close(fd);
	return (0);
}

static int	parse_component(char *s, int *value)
{
	char	*trim;
	int		i;

	trim = ft_strtrim(s, " ");
	if (!trim)
		return (1);
	i = 0;
	while (ft_isdigit(trim[i]))
		i++;
	if (i == 0 || i > 3 || trim[i] != '\0')
	{
		free(trim);
		return (1);
	}
	*value = ft_atoi(trim);
	free(trim);
	return (*value > 255);
}

static int	count_char(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
		if (*s++ == c)
			count++;
	return (count);
}

static int	set_color(int *rgb, char *s)
{
	char	**parts;
	int		i;
	int		err;

	if (rgb[0] != -1)
		return (print_error("Duplicate color"));
	parts = ft_split(s, ',');
	if (!parts)
		return (print_error("Malloc failed"));
	i = 0;
	err = 0;
	while (parts[i] && !err)
	{
		if (i >= 3 || parse_component(parts[i], &rgb[i]))
			err = 1;
		i++;
	}
	free_tab(parts);
	if (err || i != 3 || count_char(s, ',') != 2)
		return (print_error("Invalid color"));
	return (0);
}

int	parse_element(char *line, t_map *map)
{
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		return (set_texture(&map->textures[NORTH], line + 3));
	if (!ft_strncmp(line, "SO ", 3))
		return (set_texture(&map->textures[SOUTH], line + 3));
	if (!ft_strncmp(line, "WE ", 3))
		return (set_texture(&map->textures[WEST], line + 3));
	if (!ft_strncmp(line, "EA ", 3))
		return (set_texture(&map->textures[EAST], line + 3));
	if (!ft_strncmp(line, "F ", 2))
		return (set_color(map->colors.floor, line + 2));
	if (!ft_strncmp(line, "C ", 2))
		return (set_color(map->colors.sky, line + 2));
	return (print_error("Unknown identifier"));
}
