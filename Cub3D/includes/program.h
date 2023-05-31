/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:46:26 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 09:48:41 by aperrone         ###   ########.fr       */
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

# define THREE_DEG 0.0523599

# define MOVESTEP 0.3
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

typedef struct s_data
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
	float	angle;
	double	x;
	double	y;
	double	dirx;
	double	diry;
	t_point	plane;
	float	wd;
}	t_player;

// rendering delle immagini

typedef struct s_img_info
{
	unsigned int	*buf;
	int				bpp;
	int				size_line;
	int				endian;

}					t_img_info;

typedef struct s_graphic_info
{
	void			*img;
	void			*texture[4];
	int				color[2];
	t_img_info		img_info;
	t_img_info		texture_info[4];
}					t_graphic_info;

typedef struct s_render_info
{
	double					tex_pos;
	int						tex_x;
	int						tex_y;
	double					ratio;
	int						line_height;
	int						start_y;
	int						end_y;
}							t_render_info;

typedef struct s_rgB {
	int	r;
	int	g;
	int	b;
}	t_rgB;

// struct principale

typedef struct s_cub
{
	t_fetch			*fetched;
	t_data			*data;
	t_rgb			color;
	int				floor_color;
	int				ceil_color;
	t_rgB			coloR;
	t_player		player_pos;
	t_graphic_info	graphic_info;
	void			*mlx;
	void			*win;
	char			*str_tmp;
	char			**mat_tmp;
	char			**map;
	char			**minimap;
	char			*wall_imgs_addrs[5];
	char			*wall_imgs[4];
	int				player_existence;
	int				key_state[KEY_COUNT];
}	t_cub;

//start game

void			start_game(t_cub *cub);

// foos() and bars()

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			render(t_cub *cub);
int				import_elements(t_cub *cub);
int				file_validator(char *map_path);
int				game_init(t_cub *cub);
void			init_fetch(t_cub *cub);

// init img

void			init_img(t_graphic_info *graphic_info, t_cub *cub);
void			init_graphic_info(t_graphic_info *graphic_info, t_cub *cub);
void			*make_img(void *mlx_ptr, char *xpmFile);
void			insert_img(t_cub *cub);

//map_utils

int				map_normalizer(t_cub **cub);
int				map_checks(t_cub **cub);
int				map_validator(t_cub **cub);

// minimap

int				draw_minimap(t_cub *cub);
void			try_move(t_cub *cub, int key);
void			draw_rays(t_cub *cub, float mapw, int b_size);
void			draw_ray(t_cub *cub, t_ray *ray);
void			draw_line(t_player *sp, t_player *ep, t_cub *cub);
void			draw_line_x(t_player *sp, t_player *ep, t_cub *cub);
void			draw_line_y(t_player *sp, t_player *ep, t_cub *cub);

// parser

int				relist_information(t_node **info, t_fetch *fetched);
int				parser(int fd, t_cub *cub);

// parser_utils

char			*line_reparator(char *box);
int				info_adjust(t_node **info, t_fetch *fetched);
int				presence_validator(t_node *info, t_fetch *fetched);

// parser__utils

int				first_last(char *box, int *k);
int				wall_line(char *box);
int				valid_char(char c);

void			draw_player(t_cub *cub);
void			draw_game(t_cub *cub);
void			add_walls(t_cub *cub);

//player data

void			set_player_data(t_cub *cub);
void			set_player_orientation(t_cub *cub);
void			set_player_pos(t_cub *cub);
void			set_plane(t_cub *cub);

// movements

int				stop_motion(int key, t_cub *cub);
int				move(int key, t_cub *cub);
int				moves_loop(t_cub *cub, int key);
int				check_wall_collision(t_cub *cub, int key);
void			rotate_player(t_cub *cub, int key, double angle);

//raycast

t_ray			raycast(t_cub *cub, char **map, double camera_x);
void			set_ray(t_cub *cub, t_ray *ray, double camera_x);
void			set_perp_wall_dist(t_ray *ray, t_player *pos);
void			update_ray(t_ray *ray, int axis);
void			set_step(t_ray *ray);
void			set_delta_dist(t_ray *ray);
void			set_side_dist(t_ray *ray, t_player pos);

// render

t_render_info	get_render_info(t_ray *ray, t_player *player);
unsigned int	get_img_color(t_img_info *img_info, int x, int y);
int				get_texture_scaled_x(t_player *player, t_ray *ray);
void			draw_pixel(t_img_info *img_info, int x, int y, int color);

// close game

void			close_game(t_cub *cub, char *mex);
int				exit_call(t_cub *cub);

#endif
