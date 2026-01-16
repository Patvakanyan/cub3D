/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:03:30 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/15 21:15:59 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <stdbool.h>
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
}					t_ray;

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
	int				celling_color;
	int				floor_color;
	char			***wall;
}					t_data;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img			texture[4];
	t_player		player;
	t_ray			ray;
	t_data			*data;
	bool			is_game_running;
}					t_game;


#endif
