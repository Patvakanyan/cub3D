/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:11:21 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/27 17:03:36 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	key_push(int keycode, void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_E)
		interact_door(game);
	return (0);
}

int	key_release(int keycode, void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (keycode == KEY_LEFT)
		game->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_W)
		game->keys.w = 0;
	return (1);
}

void	start_game_loop(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx);
	mlx_hook(game->win, 2, 1L << 0, key_push, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0L, close_game, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_mouse_move(game->mlx, game->win, W / 2, H / 2);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	mlx_loop(game->mlx);
}
