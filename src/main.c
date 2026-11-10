/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:50:09 by romeo             #+#    #+#             */
/*   Updated: 2026/11/10 15:49:15 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	if (check_inputs(argc, argv) != 0)
// 		exit(EXIT_FAILURE);
// 	init_game(&game);
// 	if (parse_map(argv[1], &game) != 0)
// 		error_exit(&game, "Map parsing failed");
// 	if (validate_map(&game) != 0)
// 		error_exit(&game, "Invalid map");
// 	if (init_mlx(&game) != 0)
// 		error_exit(&game, "MLX initialization failed");
// 	if (start_game(&game) != 0)
// 		error_exit(&game, "Game initialization failed");
// 	free_all(&game);
// 	return (EXIT_SUCCESS);
// }

static void	debug_print(t_game *game)
{
	t_map	*m;
	int		i;

	m = &game->map;
	printf("NO: %s\nSO: %s\n", m->textures[NORTH].path,
		m->textures[SOUTH].path);
	printf("WE: %s\nEA: %s\n", m->textures[WEST].path,
		m->textures[EAST].path);
	printf("F: %d,%d,%d\n", m->colors.floor[0], m->colors.floor[1],
		m->colors.floor[2]);
	printf("C: %d,%d,%d\n", m->colors.sky[0], m->colors.sky[1],
		m->colors.sky[2]);
	printf("height: %d  width: %d\n", m->height, m->width);
	i = -1;
	while (++i < m->height)
		printf("[%s]\n", m->map[i]);
	printf("player: %c (%.1f, %.1f)\n", game->player.direction,
		game->player.position.x, game->player.position.y);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_inputs(argc, argv) != 0)
		return (EXIT_FAILURE);
	init_game(&game);
	if (parse_map(argv[1], &game) != 0)
		error_exit(&game, NULL);
	if (validate_map(&game) != 0)
		error_exit(&game, NULL);
	debug_print(&game);
	free_all(&game);
	return (EXIT_SUCCESS);
}
