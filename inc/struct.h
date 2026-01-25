/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:03:30 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/25 14:42:47 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include "./parser.h"

typedef struct s_config	t_config;

typedef enum e_texture
{
	TEX_WEST,
	TEX_EAST,
	TEX_NORTH,
	TEX_SOUTH
}					t_texture;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
}					t_player;

typedef struct s_ray
{
	double			camera_x;
	double			raydir_x;
	double			raydir_y;

	int				map_x;
	int				map_y;

	double			side_dist_x;
	double			side_dist_y;
	double			delta_x;
	double			delta_y;
	double			perp_dist;

	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				wall_dir;
}					t_ray;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				move_flag;
	int				fd;
	t_img			img;
	t_img			texture[4];
	t_player		player;
	t_ray			ray;
	t_config		*config;
}					t_game;

typedef enum e_move
{
	MOVE_NONE,
	ROTATE_LEFT,
	ROTATE_RIGHT,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_UP
}					t_move;

#endif
