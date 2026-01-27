/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:17:03 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/27 17:22:13 by rbarkhud         ###   ########.fr       */
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
			mlx_pixel_put(game->mlx, game->win,
				start_x + i, start_y + j, clr);
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
			mlx_pixel_put(game->mlx, game->win,
				px + i, py + j, MINI_PLAYER_CLR);
			++j;
		}
		++i;
	}
}

void	draw_sprite(t_game *game, t_spirit *s)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = (int)(s->x * MINI_SIZE);
	y = (int)(s->y * MINI_SIZE);
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			mlx_pixel_put(game->mlx, game->win,
				x + i, y + j, MINI_SPRITE_CLR);
			++j;
		}
		++i;
	}
}

static void	draw_map(t_game *game)
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
				draw_cell(game, x, y, MINI_WALL_CLR);
			else if (map[y][x] == 'D')
				draw_cell(game, x, y, MINI_DOOR_CLR);
			else if (map[y][x] == 'O')
				draw_cell(game, x, y, MINI_ODOR_CLR);
			else
				draw_cell(game, x, y, MINI_EMPTY_CLR);
			++x;
		}
		++y;
	}
}

void	render_minimap(t_game *game)
{
	draw_map(game);
	draw_sprites(game);
	draw_player(game);
}
