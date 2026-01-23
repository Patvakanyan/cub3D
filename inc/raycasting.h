/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:40:59 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/23 22:44:32 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../inc/cub.h"
# include "../inc/init.h"
# include "../inc/struct.h"

/* ========== GAME LOOP FUNCTIONS ========== */
void	start_game_loop(t_game *game);

/* ========== RENDERING FUNCTIONS ========== */
int		render(void *ptr);
void	put_pixel(t_img *img, int x, int y, int color);
#endif
