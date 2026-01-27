/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:50:53 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/27 17:03:10 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	init_texture_defaults(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		game->texture[i].img = NULL;
		game->texture[i].addr = NULL;
		game->texture[i].width = 0;
		game->texture[i].height = 0;
		game->texture[i].bpp = 0;
		game->texture[i].line_len = 0;
		game->texture[i].endian = 0;
		i++;
	}
}

void	set_game_defaults(t_game *game, int fd)
{
	game->mlx = NULL;
	game->win = NULL;
	game->config = NULL;
	game->player.x = 0.0;
	game->player.y = 0.0;
	game->player.dir_x = 0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	game->fd = fd;
	game->move_flag = MOVE_NONE;
	game->keys.w = 0;
	game->keys.a = 0;
	game->keys.s = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
	game->last_frame_time = 0;
	init_texture_defaults(game);
}
