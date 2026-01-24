/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:29:02 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 16:51:22 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/init.h"

int	check_file_extension(char **src, char *target)
{
	char	*ext;

	if (!src || !(*src) || !target)
		return (0);
	ext = ft_strrchr(*src, '.');
	if (!ext)
	{
		ft_putstr_fd(EXTENSION_ERR, 2);
		ft_putstr_fd(target, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	if (ft_strcmp(ext, target) == 0)
		return (1);
	ft_putstr_fd(EXTENSION_ERR, 2);
	ft_putstr_fd(target, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	flood_fill(t_map *map, int x, int y)
{
	int	len;

	if (y < 0 || y >= map->height || x < 0 || x >= map->max_width)
		return (0);
	if (!map->map[y])
		return (0);
	len = ft_strlen(map->map[y]);
	if (x >= len)
		return (0);
	if (map->map[y][x] == '1' || map->map[y][x] == 'V')
		return (1);
	map->map[y][x] = 'V';
	if (!flood_fill(map, x + 1, y))
		return (0);
	if (!flood_fill(map, x - 1, y))
		return (0);
	if (!flood_fill(map, x, y + 1))
		return (0);
	if (!flood_fill(map, x, y - 1))
		return (0);
	return (1);
}

int	validate_map(t_game *game)
{
	t_map		*copy;

	copy = copy_map(game->config->map);
	if (!copy)
		return (0);
	if (!init_player(game))
		return (free_map(copy, copy->height), 0);
	if (!find_player_pos(game, copy))
	{
		free_map(copy, copy->height);
		return (ft_putstr_fd(PLAYER_404, 2), 0);
	}
	if (!flood_fill(copy, (int)game->player.x, (int)game->player.y))
	{
		free_map(copy, copy->height);
		return (ft_putstr_fd(MAP_CLOSE_ERROR, 2), 0);
	}
	free_map(copy, copy->height);
	return (1);
}

int	validate_configs(t_game *game)
{
	if (!game->config)
		return (0);
	if (!check_file_extension(&game->config->north, ".xpm")
		|| !check_file_extension(&game->config->south, ".xpm")
		|| !check_file_extension(&game->config->east, ".xpm")
		|| !check_file_extension(&game->config->west, ".xpm"))
		return (0);
	return (validate_map(game) && check_file_destination(game->config));
}
