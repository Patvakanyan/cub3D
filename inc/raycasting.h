/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:40:59 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/23 21:58:33 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../inc/cub.h"
# include "../inc/init.h"
# include "../inc/struct.h"

void	start_game_loop(t_game *game);
int		render(void *ptr);
void	put_pixel(t_img *img, int x, int y, int color);

#endif