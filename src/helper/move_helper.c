/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:20:17 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 13:23:41 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.h"

static void	move_strafe_left(t_game *game, t_player *player, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = player->x - player->plane_x * move_speed;
	new_y = player->y - player->plane_y * move_speed;
	if (game->data->map[(int)new_y][(int)new_x] == '0')
	{
		player->x = new_x;
		player->y = new_y;
	}
}

static void	move_strafe_right(t_game *game, t_player *player, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = player->x + player->plane_x * move_speed;
	new_y = player->y + player->plane_y * move_speed;
	if (game->data->map[(int)new_y][(int)new_x] == '0')
	{
		player->x = new_x;
		player->y = new_y;
	}
}

static void	move_forward(t_game *game, t_player *player, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = player->x + player->dir_x * move_speed;
	new_y = player->y + player->dir_y * move_speed;
	if (game->data->map[(int)(new_y)][(int)(new_x)] == '0')
	{
		player->x = new_x;
		player->y = new_y;
	}
}

static void	move_backward(t_game *game, t_player *player, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = player->x - player->dir_x * move_speed;
	new_y = player->y - player->dir_y * move_speed;
	if (game->data->map[(int)(new_y)][(int)(new_x)] == '0')
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	move_player(t_game *game, char direction)
{
	t_player	*player;

	player = &game->player;
	if (direction == 'A')
		move_strafe_left(game, player, game->player.move_speed);
	else if (direction == 'D')
		move_strafe_right(game, player, game->player.move_speed);
	else if (direction == 'W')
		move_forward(game, player, game->player.move_speed);
	else if (direction == 'S')
		move_backward(game, player, game->player.move_speed);
}
