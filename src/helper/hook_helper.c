/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:49:06 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 13:49:11 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.h"

int	close_game(t_player *player)
{
	(void)player;
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

void	move_forward_backward(t_game *game, char direction)
{
	double		new_x;
	double		new_y;
	t_player	*player;

	player = &game->player;
	new_x = player->x;
	new_y = player->y;
	if (direction == 'W')
	{
		new_x += player->dir_x * game->player.move_speed;
		new_y += player->dir_y * game->player.move_speed;
	}
	else if (direction == 'S')
	{
		new_x -= player->dir_x * game->player.move_speed;
		new_y -= player->dir_y * game->player.move_speed;
	}
	if (game->data->map[(int)(new_y)][(int)(new_x)] == '0')
	{
		player->x = new_x;
		player->y = new_y;
	}
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
