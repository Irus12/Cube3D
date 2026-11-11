/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 19:14:31 by romeo             #+#    #+#             */
/*   Updated: 2026/11/11 17:20:40 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

//rajoute le player, erreur si doublon
static int	add_player(t_game *game, int y, int x)
{
	t_player	*p;

	p = &game->player;
	if (p->spawn)
		return (print_error("Multiple players"));
	p->spawn = game->map.map[y][x];
	p->position.x = x + 0.5;
	p->position.y = y + 0.5;
	game->map.map[y][x] = '0';
	return (0);
}

//Cherche le joueur unique dans la map, et retour pas trouve ou doublons
int	check_chars(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (game->map.map[y][++x])
		{
			c = game->map.map[y][x];
			if (ft_strchr("NSEW", c))
			{
				if (add_player(game, y, x))
					return (1);
			}
			else if (!ft_strchr("01 ", c))
				return (print_error("Invalid character in map"));
		}
	}
	if (!game->player.spawn)
		return (print_error("No player in map"));
	return (0);
}
