/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:20:17 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/26 03:29:17 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tools.h"

static int	can_move(t_game *game, double new_x, double new_y)
{
	int		map_x;
	int		map_y;
	char	cell;
	t_door	*door;

	map_x = (int)new_x;
	map_y = (int)new_y;
	cell = game->config->map->map[map_y][map_x];
	if (cell == '1')
		return (0);
	if (!game->config->doors)
		return (1);
	door = game->config->doors;
	while (door)
	{
		if (door->x == map_x && door->y == map_y && !door->open)
			return (0);
		door = door->next;
	}
	return (1);
}

static void	move_strafe_left(t_game *game, t_player *player, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = player->x - player->plane_x * move_speed;
	new_y = player->y - player->plane_y * move_speed;
	if (can_move(game, new_x, new_y))
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
	if (can_move(game, new_x, new_y))
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
	if (can_move(game, new_x, new_y))
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
	if (can_move(game, new_x, new_y))
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
