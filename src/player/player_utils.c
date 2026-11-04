/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:19:21 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/04 13:21:35 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cube.h"

/**
 * @brief 
 * 
 * @param player 
 */
void	player_init(t_player player)
{
	player.position = new_point(300, 300);
	player.rot_speed = 1;
	player.speed = 2;
}