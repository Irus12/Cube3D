/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:50:42 by romeo             #+#    #+#             */
/*   Updated: 2026/10/28 16:09:14 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../include/cube.h"
#include <fcntl.h>
#include <stdio.h>

static int	check_extension(char *path)
{
	int	len;

	len = 0;
	while (path[len])
		len++;
	if (len < 5)
		return (0);
	if (path[len - 4] != '.' || path[len - 3] != 'c'
		|| path[len - 2] != 'u' || path[len - 1] != 'b')
		return (0);
	return (1);
}

int	check_inputs(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		printf("Error\nExpected one .cub file\n");
		return (0);
	}
	if (!check_extension(argv[1]))
	{
		printf("Error\nInvalid map extension\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map");
		return (0);
	}
	if (close(fd) < 0)
	{
		perror("Error closing map");
		return (0);
	}
}
