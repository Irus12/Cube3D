
#include "cube.h"

void	draw_pixel(t_data *data, t_point p0)
{
	char	*dst;

	if (p0.x < 0 || p0.y < 0 || p0.x >= 1000 || p0.y >= 800)
		return ;
	dst = data->addr + (p0.y * data->line_length
			+ p0.x * (data->bits_per_pixel / 8));
	//*(unsigned int *) dst = set color here 
}

static void	param_setup(t_point *start, t_point *end,
	t_point *delta, t_point *sign)
{
	delta->x = absv(end->x - start->x);
	delta->y = absv(end->y - start->y);
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
}

void	bresenham(t_data *data, t_point start, t_point end)
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
		draw_pixel(data, c);
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
