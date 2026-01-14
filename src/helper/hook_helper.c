/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:49:06 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/14 23:13:28 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	close_game(t_player *player)
{
	(void)player;
	exit(0);
}

void	rotate_player(t_player *player, char direction)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = 0;
	old_dir_x = player->dir_x;
	if (direction == 'A') // Rotate left
		rot_speed = -0.05;
	else
		rot_speed = 0.05;
	player->dir_x = player->dir_x * cos(rot_speed) - player->dir_y
		* sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) - player->plane_y
		* sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed) + player->plane_y
		* cos(rot_speed);
}

void	move_player(t_game *game, char direction)
{
	double		move_speed;
	double		new_x;
	double		new_y;
	t_player	*player;

	player = &game->player;
	move_speed = 0.05;
	new_x = player->x;
	new_y = player->y;
	printf("Player pos before move: y=%d, x=%d\n", (int)(new_y + player->dir_y),
		(int)(new_x + player->dir_x));
	if (direction == 'W' && game->data->map[(int)(new_y + player->dir_y
			* move_speed)][(int)(new_x + player->dir_x * move_speed)] == '0')
	{
		new_x += player->dir_x * move_speed;
		new_y += player->dir_y * move_speed;
	}
	else if (direction == 'S' && game->data->map[(int)(new_y - player->dir_y
			* move_speed)][(int)(new_x - player->dir_x * move_speed)] == '0')
	{
		new_x -= player->dir_x * move_speed;
		new_y -= player->dir_y * move_speed;
	}
	player->x = new_x;
	player->y = new_y;
}

int	test_hook(int keycode, void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (keycode == KEY_ESC)
		close_game(&game->player);
	if (keycode == KEY_A)
		rotate_player(&game->player, 'A');
	if (keycode == KEY_D)
		rotate_player(&game->player, 'D');
	if (keycode == KEY_S)
		move_player(game, 'S');
	if (keycode == KEY_W)
		move_player(game, 'W');
	game->is_game_running = true;
	return (0);
}
