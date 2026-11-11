/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:27:41 by romeo             #+#    #+#             */
/*   Updated: 2026/11/10 17:04:55 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static void	free_mlx(t_game *game)
{
	int	i;

	if (!game->data.mlx)
		return ;
	i = -1;
	while (++i < 4)
		if (game->map.textures[i].img)
			mlx_destroy_image(game->data.mlx, game->map.textures[i].img);
	if (game->data.img)
		mlx_destroy_image(game->data.mlx, game->data.img);
	if (game->data.win)
		mlx_destroy_window(game->data.mlx, game->data.win);
	mlx_destroy_display(game->data.mlx);
	free(game->data.mlx);
}

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
	free_mlx(game);
	free_map(&game->map);
}

void	error_exit(t_game *game, char *msg)
{
	if (msg)
		print_error(msg);
	free_all(game);
	exit(EXIT_FAILURE);
}
