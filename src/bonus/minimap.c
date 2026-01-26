/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 01:19:55 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 15:46:20 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	draw_cell(t_game *game, int x, int y, int clr)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	i = 0;
	start_x = x * MINI_SIZE;
	start_y = y * MINI_SIZE;
	while (i < MINI_SIZE)
	{
		j = 0;
		while (j < MINI_SIZE)
		{
			mlx_pixel_put(game->mlx, game->win, start_x + i, start_y + j, clr);
			++j;
		}
		++i;
	}
}

static void	draw_player(t_game *game)
{
	int	px;
	int	py;
	int	i;
	int	j;

	i = -PLAYER_SIZE;
	px = (int)(game->player.x * MINI_SIZE);
	py = (int)(game->player.y * MINI_SIZE);
	while (i <= PLAYER_SIZE)
	{
		j = -PLAYER_SIZE;
		while (j <= PLAYER_SIZE)
		{
			mlx_pixel_put(game->mlx, game->win, px + i, py + j, 0xFF0000);
			++j;
		}
		++i;
	}
}

void	render_minimap(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->config->map->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_cell(game, x, y, 0xFFFFFF);
			else
				draw_cell(game, x, y, 0x000000);
			x++;
		}
		++y;
	}
	draw_player(game);
}
