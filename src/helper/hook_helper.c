/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:49:06 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/26 15:46:39 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}

static void	rotate_player(t_player *player, char *direction)
{
	double	old_dir_x;
	double	old_plane_x;

	if (!ft_strcmp(direction, "right"))
		player->rot_speed = 0.09;
	else
		player->rot_speed = -0.09;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(player->rot_speed) - player->dir_y
		* sin(player->rot_speed);
	player->dir_y = old_dir_x * sin(player->rot_speed) + player->dir_y
		* cos(player->rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(player->rot_speed) - player->plane_y
		* sin(player->rot_speed);
	player->plane_y = old_plane_x * sin(player->rot_speed) + player->plane_y
		* cos(player->rot_speed);
}

void	move_character(t_game *game, int direction)
{
	if (direction != -1 && direction == ROTATE_LEFT)
		rotate_player(&game->player, "left");
	if (direction != -1 && direction == ROTATE_RIGHT)
		rotate_player(&game->player, "right");
	if (direction != -1 && direction == MOVE_LEFT)
		move_player(game, 'A');
	if (direction != -1 && direction == MOVE_RIGHT)
		move_player(game, 'D');
	if (direction != -1 && direction == MOVE_UP)
		move_player(game, 'W');
	if (direction != -1 && direction == MOVE_DOWN)
		move_player(game, 'S');
}
