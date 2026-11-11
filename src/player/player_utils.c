/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:19:21 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/05 19:48:50 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cube.h"

/**
 * @brief 
 * 
 * @param player 
 */
void	player_init(t_player *player) //recast en int les position dans render
{
	player->position = new_point(0, 0);
	player->direction = new_point(50, 50);
	player->angle = 0;
	player->rot_speed = 0.05;
	player->speed = 5;
}

void	recalulate_dir(t_player *player)
{
	printf("%f\n", player->angle);
	
	double r = 100;

	if (absv(player->angle) >= 2 * M_PI)
	{
		if (player->angle >= 0)
			player->angle = (player->angle - 2 * M_PI);
		else
			player->angle = (player->angle + 2 * M_PI);
	}
	double newX = (player->position.x + (r * cos(player->angle)));
	double newY = (player->position.y + (r * sin(player->angle)));
	player->direction = new_point(newX, newY);
}