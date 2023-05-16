#ifndef CUB_TYPES_H
# define CUB_TYPES_H
# include "listft.h"
# include "fixed_types.h"

/**
 * @brief define for the cardinal directions
 */
enum e_orientations {
	NORD,
	SOUTH,
	EAST,
	WEST
} ;

/**
 * @brief union to handle color insertion in order to
 * avoid particular ambiguity (not valid values)
 */
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

/**
 * @brief main struct
 */
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

#endif //CUB3D_IN_LOVE_CUB_TYPES_H
