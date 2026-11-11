/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:06:45 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/09 18:34:34 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <include/cube.h>

void collision_check()
{
	
}
/**
 * @brief make as such that the movement controls are relative to the player
 * and not the not relative to the window frame
 * 
 * 
 * @param player 
 * @param keycode 
 */
static void mouvement_handler(t_player *player, int keycode)
{
	double	angle_shift;

	angle_shift = 0;
	if (keycode == KEY_S)
		angle_shift =  -M_PI;
	else if (keycode == KEY_A)
		angle_shift = -M_PI * 0.5;
	else if (keycode == KEY_D)
		angle_shift = +M_PI * 0.5;

	double dx = (player->position.x + (player->speed * cos(player->angle + angle_shift)));
	double dy = (player->position.y + (player->speed * sin(player->angle + angle_shift)));

	//collision_check()
	player->position = new_point(dx, dy);
}

/*
	speed and coordinat attribute inside of player

	faire un truc plus ergonomique en mode si c'est une key binded on lance

	après la reforme ca recoit juset une t_keys juste ca change rien faudra juste rename player_mouvement et player_rotation et les mettres dans player_action
*/
int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W)
		mouvement_handler(data->player, keycode);
	else if (keycode == KEY_S)
		mouvement_handler(data->player, keycode);
	else if (keycode == KEY_A)
		mouvement_handler(data->player, keycode);
	else if (keycode == KEY_D)
		mouvement_handler(data->player, keycode);
	if (keycode == KEY_L)
		data->player->angle -= data->player->rot_speed;
	else if (keycode == KEY_R)
		data->player->angle += data->player->rot_speed;
/*	if (data->player->position.x < 0)
		data->player->position.x = 0;
	if (data->player->position.x >= WIDTH)
		data->player->position.x = WIDTH - 1;
	if (data->player->position.y < 0)
		data->player->position.y = 0;
	if (data->player->position.y >= HEIGHT)
		data->player->position.y = HEIGHT - 1; */
	return (0);
}
