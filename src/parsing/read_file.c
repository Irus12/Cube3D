/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 02:14:44 by romeo             #+#    #+#             */
/*   Updated: 2026/10/30 02:16:16 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	count_lines(char *path)
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
	close(fd);
	return (count);
}

static void	strip_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static void	fill_lines(int fd, char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		lines[i] = get_next_line(fd);
		if (!lines[i])
			break ;
		strip_newline(lines[i++]);
	}
}

char	**read_file(char *path)
{
	char	**lines;
	int		count;
	int		fd;

	count = count_lines(path);
	if (count <= 0)
		return (NULL);
	lines = ft_calloc(count + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(lines);
		return (NULL);
	}
	fill_lines(fd, lines, count);
	close(fd);
	return (lines);
}
