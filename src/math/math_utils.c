/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:35:02 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/09 19:27:04 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cube.h"

double	absv(double i)
{
	if (i < 0)
		return (-i);
	return (i);
}

t_point new_point(double x, double y)
{
	t_point out;
	out.x = x;
	out.y = y;
	return (out);
}

/**
 * @brief divise l'écran avec des cases qui correspondent au tableau de **char[]
 * 
 */
void	screen_partition();

/**
 * @brief receives a postion and a map, will tell
 * 
 */
char	zone_check(t_point p1, t_map map);
