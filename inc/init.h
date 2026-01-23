/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:22:38 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/23 22:44:32 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "./cub.h"
# include "./struct.h"

/* ========== GAME INITIALIZATION FUNCTIONS ========== */
void	set_game_defaults(t_game *game);
bool	init_game(t_game *game);

/* ========== PLAYER INITIALIZATION FUNCTIONS ========== */
bool	init_player(t_game *game);

/* ========== RAY INITIALIZATION FUNCTIONS ========== */
void	init_ray(t_game *g, t_ray *r, int x);
#endif
