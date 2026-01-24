/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:22:38 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 15:12:56 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "./cub.h"
# include "./struct.h"

void	set_game_defaults(t_game *game, int fd);
bool	init_player(t_game *game);
void	init_ray(t_game *g, t_ray *r, int x);
bool	init_game(t_game *game);

#endif