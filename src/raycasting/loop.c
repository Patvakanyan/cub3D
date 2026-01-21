/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:11:21 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/21 12:23:56 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/raycasting.h"

int	key_release(int keycode, void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (keycode == KEY_LEFT)
		game->move_flag = -1;
	if (keycode == KEY_RIGHT)
		game->move_flag = -1;
	if (keycode == KEY_A)
		game->move_flag = -1;
	if (keycode == KEY_D)
		game->move_flag = -1;
	if (keycode == KEY_S)
		game->move_flag = -1;
	if (keycode == KEY_W)
		game->move_flag = -1;
	return (1);
}

int	key_push(int keycode, void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (keycode == KEY_ESC)
		close_game(&game->player);
	if (keycode == KEY_LEFT)
		game->move_flag = ROTATE_LEFT;
	if (keycode == KEY_RIGHT)
		game->move_flag = ROTATE_RIGHT;
	if (keycode == KEY_A)
		game->move_flag = MOVE_LEFT;
	if (keycode == KEY_D)
		game->move_flag = MOVE_RIGHT;
	if (keycode == KEY_S)
		game->move_flag = MOVE_DOWN;
	if (keycode == KEY_W)
		game->move_flag = MOVE_UP;
	return (0);
}

void	start_game_loop(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_push, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0L, close_game, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}
