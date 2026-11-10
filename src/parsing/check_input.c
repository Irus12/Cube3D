/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:50:42 by romeo             #+#    #+#             */
/*   Updated: 2026/11/10 15:49:51 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"
#include <fcntl.h>
#include <stdio.h>

// static int	print_error(char *msg)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(msg, 2);
// 	ft_putstr_fd("\n", 2);
// 	return (1);
// }

int	check_inputs(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		return (print_error("Usage: ./cub3D <map.cub>"));
	len = ft_strlen(argv[1]);
	if (len <= 4 || ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0)
		return (print_error("Map file must have .cub extension"));
	if (argv[1][len - 5] == '/')
		return (print_error("Invalid map file name"));
	return (0);
}
