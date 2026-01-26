/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 01:03:40 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 02:54:06 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bonus.h"

int	mouse_move(int x, int y, t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	(void)y;
	if (!game)
		return (0);
	if (x < 0 || x > W)
		return (0);
	rot = (x - (W / 2)) * 0.002;
	if (rot == 0)
		return (0);
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot)
		- game->player.dir_y * sin(rot);
	game->player.dir_y = old_dir_x * sin(rot)
		+ game->player.dir_y * cos(rot);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot)
		- game->player.plane_y * sin(rot);
	game->player.plane_y = old_plane_x * sin(rot)
		+ game->player.plane_y * cos(rot);
	mlx_mouse_move(game->mlx, game->win, W / 2, H / 2);
	return (0);
}
