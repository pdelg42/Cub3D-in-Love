/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:46:26 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/12 19:58:49 by gdel-giu         ###   ########.fr       */
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

// struct necessaria (da guida) per poter disegnare e gesire i
// pixel di un'immagine e stamparla a video

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
int		parse_map(t_cub *cub, char *map_path);
int		import_elements(t_cub *cub);

#endif
