/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:22:06 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/11 16:51:51 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <minilibx-linux/mlx.h>
# include "libft_merged/include/libft.h"

# define WIDTH		800
# define HEIGHT		600

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

# define NORTH		0
# define SOUTH		1
# define WEST		2
# define EAST		3

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_data;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

/*
structure relative to the color of the sky and ground
*/
// typedef struct s_color_data
// {
// 	int	sky_r;
// 	int	sky_g;
// 	int	sky_b;
// 	int	floor_r;
// 	int	floor_g;
// 	int	floor_b;
// }	t_color_data;

typedef struct s_color_data
{
	int	sky[3];
	int	floor[3];
}	t_color_data;

/*
on doit afficher la texture pixel par pixel et c'est toujours un version downscale qui est affiché car 
la texture ingame s'agrandit/rétrécit comparé à la "vrai" image.
c’est une règle de trois pour le choix (en coordonée) du pixel qu'on séléctionne dans la vrai image 
et qu'on décide d'afficher
*/
// typedef struct s_texture ///a completer
// {
// 	char	*path;

// }	t_texture;

typedef struct s_texture
{
	char	*path;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

/*
représente une map avec son array logique qui représente le monde explorable
player en position (x ; y) (0.1 ; 1.5) -> map (0 ; 1) -> map[y][x] map[1][0]
*/
typedef struct s_map
{
	t_texture		textures[4]; ///changed
	t_color_data	colors;
	char			**map;
	char			*path;
	int				height;
	int				width;
}	t_map;

// typedef struct s_player
// {
// 	t_point	position;
// 	char	direction; //rajouted
// }	t_player;

//Romeo 

typedef struct s_player
{
	t_point	position;
	char	direction;
}	t_player;

typedef struct s_game
{
	t_data		data;
	t_map		map;
	t_player	player;
}	t_game;

//Parsing

int		print_error(char *msg);

int		check_inputs(int argc, char **argv);

void	init_game(t_game *game);

int		is_empty_line(char *line);
char	**read_file(char *path);
int		dispatch_element(char *line, t_map *map);
int		parse_map(char *path, t_game *game);

int		check_chars(t_game *game);
int		validate_map(t_game *game);

int		init_mlx(t_game *game);

int		start_game(t_game *game);

void	free_tab(char **tab);
void	free_map(t_map *map);
void	free_all(t_game *game);
void	error_exit(t_game *game, char *msg);

#endif