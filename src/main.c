/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:50:09 by romeo             #+#    #+#             */
/*   Updated: 2026/10/28 16:16:23 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"


#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data		data;
	t_map		map;
	t_player	player;

	if (!check_inputs(argc, argv))
		exit(EXIT_FAILURE);
	init_structs(&data, &map, &player);
	if (parse_map(argv[1], &map) != 0)
		error_exit(&data, &map, "Map parsing failed");
	if (validate_map(&map, &player) != 0)
		error_exit(&data, &map, "Invalid map");
	if (init_mlx(&data, &map) != 0)
		error_exit(&data, &map, "MLX initialization failed");
	if (start_game(&data, &map, &player) != 0)
		error_exit(&data, &map, "Game initialization failed");
	free_all(&data, &map);
	return (EXIT_SUCCESS);
}
