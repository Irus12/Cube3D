/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:50:09 by romeo             #+#    #+#             */
/*   Updated: 2026/11/11 16:49:21 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_inputs(argc, argv) != 0)
		exit(EXIT_FAILURE);
	init_game(&game);
	if (parse_map(argv[1], &game) != 0)
		error_exit(&game, NULL);
	if (validate_map(&game) != 0)
		error_exit(&game, NULL);
	if (init_mlx(&game) != 0)
		error_exit(&game, NULL);
	if (start_game(&game) != 0)
		error_exit(&game, NULL);
	free_all(&game);
	return (EXIT_SUCCESS);
}
