/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:03:30 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 15:37:23 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include "./parser.h"

typedef struct s_config	t_config;

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
}					t_ray;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				fd;
	t_img			img;
	t_img			texture[4];
	t_player		player;
	t_ray			ray;
	t_config		*config;
}					t_game;

#endif