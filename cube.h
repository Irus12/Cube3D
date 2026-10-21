# include <math.h>
# include <stdlib.h>

typdef struct s_point
{
	double	x;
	double	y;
}	t_point;

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
} t_color_data;

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

typedef struct s_player
{
	t_point position;

}	t_player;