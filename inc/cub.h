/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:08 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/13 17:51:55 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include "mlx.h"

# define W 1000
# define H 1000
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define TEX 64

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	int		map_x;
	int		map_y;

	double	side_dist_x;
	double	side_dist_y;
	double	delta_x;
	double	delta_y;
	double	perp_dist;

	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;


typedef enum s_type
{
	WALL,
	CEILING_FLOOR,
	MAP
}					t_type;

typedef struct s_map
{
	char			**row;
	t_type			type;
	struct s_map	*next;
}					t_map;

typedef struct s_data
{
	char			**map;
	char			**celling_floor;
	char			***wall;
}					t_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		texture[4];
	t_player	player;
	t_ray		ray;
	t_data		*data;
}	t_game;

int					validate_file_open(char *file);
int					render(t_game *game);
bool				init_game(t_game *game);
int					chek_row(char *tmp);
int					get_type(char *tmp);
void				free_list(t_map *list);
t_map				*give_list_map(int fd);
void				free_split(char **tmp);
void				free_split_all(char ***split);
void				free_data(t_data *data);
void				free_game(t_game *game);
int					is_wall_row(char *row);
char				*ft_splitdup(char **str);

bool				check_single_parameter(t_map *tmp, char *param,
						t_type type);
bool				pars_map(char *file, t_game *game);
char				**extract_map(t_map **map);
int					get_map_size(t_map *map);
bool				has_extension(char *file, char *extension, char *msg);
bool				check_map_line(char **line);
bool				check_first_last_row(char *row);
int					get_size_of_split(char **split);


void				put_pixel(t_img *img, int x, int y, int color);
char				*replace_space_with_zero(char **row);
#endif
