/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:06:45 by nschilli          #+#    #+#             */
/*   Updated: 2026/10/26 20:08:52 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube.h>


/*
	speed and coordinat attribute inside of player
*/
static int	key_press(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
		close_window(d);
	else if (keycode == KEY_W)
		d->y -= SPEED;
	else if (keycode == KEY_S)
		d->y += SPEED;
	else if (keycode == KEY_A)
		d->x -= SPEED;
	else if (keycode == KEY_D)
		d->x += SPEED;
	if (d->x < 0)
		d->x = 0;
	if (d->x >= WIDTH)
		d->x = WIDTH - 1;
	if (d->y < 0)
		d->y = 0;
	if (d->y >= HEIGHT)
		d->y = HEIGHT - 1;
	return (0);
}