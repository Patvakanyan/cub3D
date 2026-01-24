/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:15:08 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 15:29:58 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

t_map	*copy_map(t_map *src_map)
{
	int		i;
	t_map	*new_map;

	new_map = init_map(src_map->height);
	if (!new_map)
		return (ft_putstr_fd(ALLOC_ERR, 2), NULL);
	i = 0;
	while (i < src_map->height)
	{
		new_map->map[i] = ft_strdup(src_map->map[i]);
		if (!new_map->map[i])
		{
			ft_putstr_fd(ALLOC_ERR, 2);
			free_map(new_map, i);
			return (NULL);
		}
		++i;
	}
	new_map->height = src_map->height;
	new_map->max_width = src_map->max_width;
	return (new_map);
}

int	find_player_pos(t_game *game, t_map *map)
{
	t_coords	coords;
	int			player_count;

	coords.y = -1;
	player_count = 0;
	while (++coords.y < map->height)
	{
		coords.x = -1;
		while (++coords.x < (int)ft_strlen(map->map[coords.y]))
		{
			if (!is_valid_char(map->map[coords.y][coords.x]))
				return (0);
			if (is_player(map->map[coords.y][coords.x]))
			{
				if (check_player_pos(map, coords.x, coords.y))
					return (0);
				player_count++;
				game->player.x = coords.x + 0.5;
				game->player.y = coords.y + 0.5;
				init_player_dir(&game->player, map->map[coords.y][coords.x]);
				game->config->map->map[coords.y][coords.x] = '0';
			}
		}
	}
	return (player_count == 1);
}
