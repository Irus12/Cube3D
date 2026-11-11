/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:22:06 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/11 15:45:15 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <minilibx-linux/mlx.h>
# include "libft_merged/include/libft.h"

#define WIDTH	800
#define HEIGHT	600

#define KEY_ESC	65307
#define KEY_W	119
#define KEY_A	97
#define KEY_S	115
#define KEY_D	100
#define KEY_L	65361
#define KEY_R	65363

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

/**
 * @brief Handles the transmission of the keyboard inputs
 * to the game state waiting to be updated.
 * The values are set to 1 if the key is pressed otherwise it's 0.
 * This struct is used so the player can use multiples keys at once.
 */
typedef struct s_keys
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_left_arrow;
	int	key_right_arrow;
}	t_key;

typedef struct s_player
{
	t_point		position;
	t_point		direction;
	double		angle;
	double		speed;
	double		rot_speed;
}	t_player;

/**
 * @brief Struct used to store data relative
 * to the current game simulation, the screen's render and minilibx's window
 */
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_player *player;
}	t_data;

/*
structure relative to the color of the sky and ground
*/
typedef struct s_color_data
{
	int	sky_r;
	int	sky_g;
	int	sky_b;
	int	floor_r;
	int	floor_g;
	int	floor_b;
}	t_color_data;

/*
on doit afficher la texture pixel par pixel et c'est toujours un version downscale qui est affiché car 
la texture ingame s'agrandit/rétrécit comparé à la "vrai" image.
c’est une règle de trois pour le choix (en coordonée) du pixel qu'on séléctionne dans la vrai image 
et qu'on décide d'afficher
*/
typedef struct s_texture
{
	char	*path;

}	t_texture;

/*
représente une map avec son array logique qui représente le monde explorable
player en position (x ; y) (0.1 ; 1.5) -> map (0 ; 1) -> map[y][x] map[1][0]
*/
typedef struct s_map
{
	t_texture		*textures;
	t_color_data	colors;
	char			**map;
	char			*path;
	int				height;
	int				width;
}	t_map;

/* PLAYER */
void	player_init(t_player *player);
void	player_move(t_player *player, t_key keys);
void	recalulate_dir(t_player *player);
void	update_player(t_data *data);

/* INPUT*/
int		key_press(int keycode, t_data *data);

/* RENDERING */
void	draw_line(t_data *data, t_point start, t_point end);
void	draw_circle(t_data *data, t_point center, int radius, int color);
void	render_player(t_data *data);


/* MATH */
double		absv(double i);
t_point		new_point(double x, double y);

/* MINILIBX */
int	close_window(t_data *d);

#endif