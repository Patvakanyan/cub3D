/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:11:21 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/16 23:24:23 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/raycasting.h"

void	start_game_loop(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, test_hook, game);
	mlx_hook(game->win, 17, 0L, close_game, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}
