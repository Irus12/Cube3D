/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:06:45 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/04 02:52:11 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <include/cube.h>


/*
	speed and coordinat attribute inside of player
*/
int	key_press(int keycode, t_data *d ,t_player *p)
{
	if (keycode == KEY_ESC)
		close_window(d);
	else if (keycode == KEY_W)
		p->position.x -= p->speed;
	else if (keycode == KEY_S)
		p->position.y += p->speed;
	else if (keycode == KEY_A)
		p->position.x -= p->speed;
	else if (keycode == KEY_D)
		p->position.x += p->speed;
	if (p->position.x < 0)
		p->position.x = 0;
	if (p->position.x >= WIDTH)
		p->position.x = WIDTH - 1;
	if (p->position.y < 0)
		p->position.y = 0;
	if (p->position.y >= HEIGHT)
		p->position.y = HEIGHT - 1;
	return (0);
}