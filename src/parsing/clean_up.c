/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:27:41 by romeo             #+#    #+#             */
/*   Updated: 2026/10/30 16:44:12 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(map->textures[i].path);
		map->textures[i].path = NULL;
		i++;
	}
	free_tab(map->map);
	map->map = NULL;
}

void	free_all(t_game *game)
{
	free_map(&game->map);
}

void	error_exit(t_game *game, char *msg)
{
	if (msg)
		print_error(msg);
	free_all(game);
	exit(EXIT_FAILURE);
}
