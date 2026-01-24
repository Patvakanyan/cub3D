/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:49:06 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 15:28:28 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tools.h"

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}

static void	rotate_player(t_player *player, char *direction)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	if (!ft_strcmp(direction, "right"))
		player->rot_speed = -0.1;
	else
		player->rot_speed = 0.1;
	player->dir_x = player->dir_x * cos(player->rot_speed) - player->dir_y
		* sin(player->rot_speed);
	player->dir_y = old_dir_x * sin(player->rot_speed) + player->dir_y * cos(player->rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(player->rot_speed) - player->plane_y
		* sin(player->rot_speed);
	player->plane_y = old_plane_x * sin(player->rot_speed) + player->plane_y
		* cos(player->rot_speed);
}

static void	move_player(t_game *game, char direction)
{
	double		move_speed;
	double		new_x;
	double		new_y;
	t_player	*player;

	player = &game->player;
	move_speed = 0.1;
	new_x = player->x;
	new_y = player->y;
	if (direction == 'A')
	{
		new_x = player->x - player->dir_y * move_speed;
		new_y = player->y + player->dir_x * move_speed;
		printf("zibil1 == [%d]\n",game->config->map->map[(int)(new_y)][(int)(new_x)]);
		if (game->config->map->map[(int)(new_y)][(int)(new_x)] == '0')
		{
			player->x = new_x;
			player->y = new_y;
		}
		printf("new_x %f new_y %f dir_x %f dir_y %f\n", new_x, new_y,
			player->dir_x, player->dir_y);
	}
	else if (direction == 'D')
	{
		new_x = player->x + player->dir_y * move_speed;
		new_y = player->y - player->dir_x * move_speed;
		if (game->config->map->map[(int)(new_y)][(int)(new_x)] == '0')
		{
			player->x = new_x;
			player->y = new_y;
		}
		printf("here %f %f dir_x %f dir_y %f\n", new_x, new_y, player->dir_x,
			player->dir_y);
	}
	else if (direction == 'W')
	{
		new_x += player->dir_x * move_speed;
		new_y += player->dir_y * move_speed;
		if (game->config->map->map[(int)(new_y)][(int)(new_x)] == '0')
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	else if (direction == 'S')
	{
		new_x -= player->dir_x * move_speed;
		new_y -= player->dir_y * move_speed;
		if (game->config->map->map[(int)(new_y)][(int)(new_x)] == '0')
		{
			player->x = new_x;
			player->y = new_y;
			}
		}
}

void move_forward_backward(t_game *game, char direction)
{
	double	new_x;
	double	new_y;
	t_player	*player;

	player = &game->player;
	new_x = player->x;
	new_y = player->y;
	if (direction == 'W')
	{
		new_x += player->dir_x * game->player.move_speed;
		new_y += player->dir_y * game->player.move_speed;
		if (game->config->map->map[(int)(new_y)][(int)(new_x)] == '0')
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	else if (direction == 'S')
	{
		new_x -= player->dir_x * game->player.move_speed;
		new_y -= player->dir_y * game->player.move_speed;
		if (game->config->map->map[(int)(new_y)][(int)(new_x)] == '0')
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
}

int	test_hook(int keycode, void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	printf("test key = %d\n", keycode);
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_LEFT)
		rotate_player(&game->player, "left");
	if (keycode == KEY_RIGHT)
		rotate_player(&game->player, "right");
	if (keycode == KEY_A)
		move_player(game, 'A');
	if (keycode == KEY_D)
		move_player(game, 'D');
	if (keycode == KEY_S)
		move_player(game, 'S');
	if (keycode == KEY_W)
		move_player(game, 'W');
	return (0);
}
