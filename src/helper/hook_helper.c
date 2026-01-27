/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:49:06 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/27 16:58:00 by rbarkhud         ###   ########.fr       */
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
		player->rot_speed = 0.05;
	else
		player->rot_speed = -0.05;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x
		* cos(player->rot_speed) - player->dir_y * sin(player->rot_speed);
	player->dir_y = old_dir_x
		* sin(player->rot_speed) + player->dir_y * cos(player->rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x
		* cos(player->rot_speed) - player->plane_y * sin(player->rot_speed);
	player->plane_y = old_plane_x
		* sin(player->rot_speed) + player->plane_y * cos(player->rot_speed);
}

void	handle_movement(t_game *game)
{
	if (game->keys.left)
		rotate_player(&game->player, "left");
	if (game->keys.right)
		rotate_player(&game->player, "right");
	if (game->keys.a)
		move_player(game, 'A');
	if (game->keys.d)
		move_player(game, 'D');
	if (game->keys.w)
		move_player(game, 'W');
	if (game->keys.s)
		move_player(game, 'S');
}
