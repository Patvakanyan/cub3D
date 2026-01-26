/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:40:59 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/26 15:45:48 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "./cub.h"

typedef struct s_img	t_img;
typedef struct s_game	t_game;
typedef struct s_door	t_door;

/* ========== GAME LOOP FUNCTIONS ========== */
void	start_game_loop(t_game *game);

/* ========== RENDERING FUNCTIONS ========== */
t_door	*get_door_at(t_game *game, int x, int y);
int		render(void *ptr);
void	put_pixel(t_img *img, int x, int y, int color);

#endif