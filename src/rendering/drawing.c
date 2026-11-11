/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:22:00 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/11 15:42:21 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cube.h"

void	draw_pixel(t_data *data, t_point p0, int color)
{
	char	*dst;
	int		x;
	int		y;

	if (p0.x < 0 || p0.y < 0)
		return ;
	x = p0.x;
	y = p0.y;
	if (x>= WIDTH || y>=HEIGHT)
		return ;
	dst = data->addr + (int) (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

/**
 * @brief 
 * 
 * @param start 
 * @param end 
 * @param delta 
 * @param sign 
 */
static void	param_setup(t_point *start, t_point *end,
	t_point *delta, t_point *sign)
{
	*start = new_point((int)start->x, (int)start->y);
	*end = new_point((int)end->x, (int)end->y);

	delta->x = absv(end->x - start->x);
	delta->y = absv(end->y - start->y);
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
}

/*
	use the bressenham algorithm to draw a line
*/
void	draw_line(t_data *data, t_point start, t_point end)
{
	t_point	c;
	t_point	sign;
	t_point	delta;
	int		line;
	int		tmp;

	param_setup(&start, &end, &delta, &sign);
	line = delta.x - delta.y;
	c = start;
	while (c.x != end.x || c.y != end.y)
	{
		draw_pixel(data, c, 0xFFFF);
		tmp = line * 2;
		if (tmp > -delta.y)
		{
			line -= delta.y;
			c.x += sign.x;
		}
		if (tmp < delta.x)
		{
			line += delta.x;
			c.y += sign.y;
		}
	}
}

void	draw_circle(t_data *data, t_point center, int radius, int color)
{
	int	dx;
	int	dy;
 
	dy = -radius;
	while (dy <= radius)
	{
		dx = -radius;
		while (dx <= radius)
		{
			if (dx * dx + dy * dy <= radius * radius)
				draw_pixel(
					data,
					new_point((int)center.x + dx, (int)center.y + dy),
					color);
			dx++;
		}
		dy++;
	}
}

