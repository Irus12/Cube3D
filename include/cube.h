/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:22:06 by nschilli          #+#    #+#             */
/*   Updated: 2026/11/11 16:25:37 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <minilibx-linux/mlx.h>
# include "libft_merged/include/libft.h"
# include <fcntl.h>
# include <unistd.h>

#define WIDTH	800
#define HEIGHT	600

#define KEY_ESC	65307
#define KEY_W	119
#define KEY_A	97
#define KEY_S	115
#define KEY_D	100
#define KEY_L	65361
#define KEY_R	65363

# define NORTH	0
# define SOUTH	1
# define WEST	2
# define EAST	3


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

/*
on doit afficher la texture pixel par pixel et c'est toujours un version downscale qui est affiché car 
la texture ingame s'agrandit/rétrécit comparé à la "vrai" image.
c’est une règle de trois pour le choix (en coordonée) du pixel qu'on séléctionne dans la vrai image 
et qu'on décide d'afficher
*/
typedef struct s_texture ///a completer
{
	char	*path;

}	t_texture;

typedef struct s_player
{
	t_point		position;
	t_point		direction;
	double		angle;
	double		speed;
	double		rot_speed;
}	t_player;

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

typedef struct s_game
{
	t_map		map;
	t_player	player;
}	t_game;

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
	t_game *game;
}	t_data;


typedef struct s_color_data
{
	int	sky[3];
	int	floor[3];
}	t_color_data;




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

//Romeo
/* PARSING */

int		check_inputs(int argc, char **argv);

void	init_game(t_game *game);

// int		parse_map(char *path, t_map *map, t_player *player);
// int		count_lines(char *path);
// int		read_map(char *path, t_map *map);
// void	free_map(t_map *map);
// int		validate_map(t_map *map, t_player *player);
// int		read_map(char *path, t_map *map);
// int		count_lines(char *path);
// void	free_map(t_map *map);

int		print_error(char *msg);
void	free_tab(char **tab);
int		is_empty_line(char *line);
char	**read_file(char *path);
int		parse_element(char *line, t_map *map);
int		parse_map(char *path, t_game *game);

void	free_map(t_map *map);
void	free_all(t_game *game);
void	error_exit(t_game *game, char *msg);


#endif