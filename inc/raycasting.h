/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:40:59 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/16 17:44:13 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../inc/cub.h"
# include "../inc/struct.h"
# include "../inc/init.h"

void	start_game_loop(t_game *game);
int		render(void *ptr);
#endif
