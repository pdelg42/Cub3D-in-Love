/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:46:26 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/15 10:19:39 by aperrone         ###   ########.fr       */
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

# define WIN_SIZE_W 1028
# define WIN_SIZE_H 720

# define TILE_SIZE 64

// enums per definire gli orientamenti di base
// 0 -> 3

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
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// struct principale

typedef struct s_cub
{
	t_fetch	*fetched;
    t_data  *data;
	t_rgb	color;
	t_rgb	*floor_color;
	t_rgb	*ceil_color;
	t_point	player_pos;
    void    *mlx;
    void    *win;
	char	*str_tmp;
	char	**mat_tmp;
	char	**map;
	char	*wall_imgs_addrs[5];
	char	*wall_imgs[4];
}   t_cub;

// foos() and bars()

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    render(t_cub *cub);
int		parser(int fd, t_cub *cub);
int		import_elements(t_cub *cub);
int		file_validator(char *map_path);
int		game_init(t_cub *cub);
void	init_fetch(t_cub *cub);

// minimap

int		draw_minimap(t_cub* cub, int playerx, int playery);
void	minimove(t_cub* cub, int key);


#endif
