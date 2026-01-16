/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:50:53 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/16 23:24:47 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/init.h"

static void	init_texture_defaults(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
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

void	set_game_defaults(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->data = NULL;
	game->player.x = 0.0;
	game->player.y = 0.0;
	game->player.dir_x = 0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	init_texture_defaults(game);
}
