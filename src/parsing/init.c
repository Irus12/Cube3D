/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:53:36 by romeo             #+#    #+#             */
/*   Updated: 2026/11/11 17:15:37 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// Met tout à zéro, relie data au jeu et marque les couleurs comme non lues
void	init_game(t_data *data, t_game *game)
{
	ft_bzero(data, sizeof(t_data));
	ft_bzero(game, sizeof(t_game));
	data->game = game;
	game->map.colors.sky[0] = -1;
	game->map.colors.floor[0] = -1;
}