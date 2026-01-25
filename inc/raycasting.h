/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:40:59 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/26 01:32:48 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "./cub.h"
# include "./init.h"
# include "./struct.h"

typedef struct s_img	t_img;

/* ========== GAME LOOP FUNCTIONS ========== */
void	start_game_loop(t_game *game);

/* ========== RENDERING FUNCTIONS ========== */
int		render(void *ptr);
void	render_minimap(t_game *game);
void	put_pixel(t_img *img, int x, int y, int color);

#endif