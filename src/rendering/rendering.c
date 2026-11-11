/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:50:07 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/09 16:52:40 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cube.h"

/**
 * @brief render the player with it's direction vector
 * 
 * @param data data relative to the game simulation parameters and MLX.
 */
void	render_player(t_data *data)
{
	draw_circle(data, data->player->position, 6, 0xFFFFFF);
	draw_line(data, data->player->position, data->player->direction);
	draw_circle(data, data->player->direction, 3, 0xFF0000);
}

