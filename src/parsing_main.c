/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:50:09 by romeo             #+#    #+#             */
/*   Updated: 2026/11/11 17:18:15 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_game	game;

	if (check_inputs(argc, argv) != 0)
		return (EXIT_FAILURE);
	init_game(&data, &game);
	if (parse_map(argv[1], &game) != 0)
		error_exit(&data, NULL);
	if (validate_map(&game) != 0)
		error_exit(&data, NULL);
	if (init_mlx(&data) != 0)
		error_exit(&data, NULL);
	if (start_game(&data) != 0)
		error_exit(&data, NULL);
	free_all(&data);
	return (EXIT_SUCCESS);
}
