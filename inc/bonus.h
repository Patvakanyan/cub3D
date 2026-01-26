/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:49:25 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 20:33:27 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H

# define BONUS_H

# include "./cub.h"

# define MINI_SIZE 5
# define PLAYER_SIZE 3

typedef struct s_game	t_game;
typedef struct s_door	t_door;
typedef struct s_spirit	t_spirit;
typedef struct s_config	t_config;

typedef struct s_spirit_configs
{
	double	dx;
	double	dy;
	double	dist;
	double	step;
	double	x;
	double	y;
}	t_spirit_configs;

typedef struct s_draw_spirit
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_src_x;
	int		sprite_h;
	int		sprite_w;
	int		draw_start_y;
	int		draw_end_y;
	int		draw_start_x;
	int		draw_end_x;
	int		x;
	int		tex_x;
}	t_draw_spirit;

/*-----mouse hook handler-----*/
int		mouse_move(int x, int y, t_game *game);

/*-----minimap rendering-----*/
void	render_minimap(t_game *game);

/*-----doors-----*/
int		add_door(t_door **head, int x, int y);
void	interact_door(t_game *game);
int		can_move(t_game *game, double new_x, double new_y);
int		parse_bonus_line(t_config *config, char *row, int y);

/*-----spirits-----*/
void	update_spirits(t_game *game);
void	render_spirits(t_game *game);
int		add_spirit(t_spirit **head, int x, int y);
int		spirit_can_see_player(t_game *g, t_spirit *s);
void	move_spirit_towards_player(t_game *game, t_spirit *s);
void	draw_spirit_pixels(t_game *g, t_draw_spirit d);

/*-----dealloc funtions-----*/
void	free_doors(t_door *head);
void	free_spirits(t_spirit *head);

#endif