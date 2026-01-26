/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:11:28 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/26 04:27:10 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "../libft/libft.h"
# include "./cub.h"
# include "./struct.h"
# include "./bonus.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

/* ========== INPUT/EVENT FUNCTIONS ========== */
int		key_push(int keycode, void *ptr);

/* ========== MOVEMENT FUNCTIONS ========== */
void	move_player(t_game *game, char direction);
void	move_character(t_game *game, int direction);

/* ========== RAYCASTING HELPER FUNCTIONS ========== */
void	put_pixel(t_img *img, int x, int y, int color);
void	step_and_side(t_game *g, t_ray *r);
void	dda(t_game *g, t_ray *r);
int		get_tex_color(t_img *tex, int tex_x, int tex_y);

/* ========== MEMORY MANAGEMENT FUNCTIONS ========== */
void	free_game(t_game *game);

#endif