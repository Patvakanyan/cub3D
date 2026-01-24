/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checkers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:12:37 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 15:07:07 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	check_player_pos(t_map *map, int x, int y)
{
	return (y == 0 || y == map->height - 1
		|| x == 0 || x == map->max_width - 1
		|| (y > 0 && map->map[y - 1][x] == ' ')
		|| (y < map->height - 1 && map->map[y + 1][x] == ' ')
		|| (x > 0 && map->map[y][x - 1] == ' ')
		|| (x < map->max_width - 1 && map->map[y][x + 1] == ' '));
}
