/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:46:26 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/26 14:37:56 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "libft.h"
# include "listft.h"
# include "get_next_line.h"

# include "../mlx/mlx.h"
# include "../fixed/fixed.h"
# include "point.h"
# include "gc.h"

# define WIN_SIZE_W 1080
# define WIN_SIZE_H 720

# define TILE_SIZE 64

# define MAX_MAP_PARAMS 6

# define KEY_COUNT 256

# define FOV_ANGLE 60.0

# define ONE_DEG 0.0174533
// enums per definire gli orientamenti di base
// 0 -> 3

# define MINI_WIN_SIZE 400

typedef struct s_ray
{
	t_point	ray_dir;
	t_point	side_dist;
	t_point	delta_dist;
	int		map_x;
	int		map_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	double	ratio;
}			t_ray;

enum e_orientations {
	NORD = 1,
	SOUTH, 
	EAST,
	WEST
} ;

// union da utilizzare per gestire l'inserimento dei colori
// evitando ambiguitá particolari (generalmente valori non idonei)

typedef union u_rgb {
	unsigned int	rgb;
	unsigned char	col_param;
}	t_rgb;

typedef struct s_fetch
{
	t_node		*paths;
	t_node		*colors;
	t_node		*map;
	t_node		*p_t;
	t_node		*checks;
	char		**paths_mtx;
	char		**map_mtx;
	char		*colors_str;
	int			len;
}	t_fetch;

typedef struct	s_data 
{
	void	*img;
	void	*img2;
	char	*addr;
	char	*addr2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player 
{
	float angle;
	double x;
	double y;
	double dirx;
	double diry;
	t_point plane;
	float wd;

} t_player;

// struct principale

typedef struct s_cub
{
	t_fetch		*fetched;
    t_data  	*data;
	t_rgb		color;
	t_rgb		*floor_color;
	t_rgb		*ceil_color;
	t_player	player_pos;
    void   	*mlx;
    void   	*win;
	char	*str_tmp;
	char	**mat_tmp;
	char	**map;
	char	**minimap;
	char	*wall_imgs_addrs[5];
	char	*wall_imgs[4];
	int		player_existence;
	int		wstate;
	int		sstate;
	int		astate;
	int		dstate;
	int		key_state[KEY_COUNT];
}   t_cub;

// foos() and bars()

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	render(t_cub *cub);
int		import_elements(t_cub *cub);
int		file_validator(char *map_path);
int		game_init(t_cub *cub);
void	init_fetch(t_cub *cub);

//map_utils

int		map_normalizer(t_cub **cub);
int		map_checks(t_cub **cub);
int		map_validator(t_cub **cub);

// minimap

int		draw_minimap(t_cub* cub);
void	minimove(t_cub* cub, int key);
void	add_map_padding(t_cub* cub);

// parser

int		parser(int fd, t_cub *cub);

// parser_utils

char	*line_reparator(char *box);
int		info_adjust(t_node **info, t_fetch *fetched);
int		presence_validator(t_node *info, t_fetch *fetched);

// parser__utils

int		first_last(char *box, int *k);
int		wall_line(char *box);
int		valid_char(char c);

void	draw_player(t_cub* cub, float x, float y, float a, int key);
void	draw_game(t_cub* cub);
void	add_walls(t_cub *cub);

//player data

void		define_player_orientation(t_cub* cub);
t_player	*define_player_pos(t_cub* cub);
void		set_plane(t_cub *cub);

//raycast

t_ray	raycast(t_cub *cub, char **map, double camera_x);

#endif
