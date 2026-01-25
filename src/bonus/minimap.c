/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 01:19:55 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 01:25:00 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	draw_cell(t_game *game, int x, int y, int color)
{
	int	i, j;
	int	start_x = x * MINI_SIZE;
	int	start_y = y * MINI_SIZE;

	for (i = 0; i < MINI_SIZE; i++)
		for (j = 0; j < MINI_SIZE; j++)
			mlx_pixel_put(game->mlx, game->win, start_x + i, start_y + j, color);
}

static void	draw_player(t_game *game)
{
	int px = (int)(game->player.x * MINI_SIZE);
	int py = (int)(game->player.y * MINI_SIZE);
	int i, j;

	for (i = -PLAYER_SIZE; i <= PLAYER_SIZE; i++)
		for (j = -PLAYER_SIZE; j <= PLAYER_SIZE; j++)
			mlx_pixel_put(game->mlx, game->win, px + i, py + j, 0xFF0000);
}

void	render_minimap(t_game *game)
{
	int x, y;
	char **map = game->config->map->map;

	for (y = 0; map[y]; y++)
		for (x = 0; map[y][x]; x++)
			if (map[y][x] == '1')
				draw_cell(game, x, y, 0xFFFFFF);
			else
				draw_cell(game, x, y, 0x000000);

	draw_player(game);
}
