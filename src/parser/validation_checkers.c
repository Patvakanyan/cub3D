/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checkers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:12:37 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 17:07:06 by rbarkhud         ###   ########.fr       */
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

int	check_file_destination(t_config *config)
{
	int	fd_north;
	int	fd_south;
	int	fd_east;
	int	fd_west;

	fd_north = open(config->north, O_RDONLY);
	if (fd_north == -1)
		return (ft_putstr_fd(NORTH_FD_ERR, 2), 0);
	fd_south = open(config->south, O_RDONLY);
	if (fd_south == -1)
		return (close(fd_north), ft_putstr_fd(SOUTH_FD_ERR, 2), 0);
	fd_east = open(config->east, O_RDONLY);
	if (fd_east == -1)
		return (close(fd_north), close(fd_south),
			ft_putstr_fd(EAST_FD_ERR, 2), 0);
	fd_west = open(config->west, O_RDONLY);
	if (fd_west == -1)
		return (close(fd_north), close(fd_south), close(fd_east),
			ft_putstr_fd(WEST_FD_ERR, 2), 0);
	close(fd_north);
	close(fd_south);
	close(fd_east);
	close(fd_west);
	return (1);
}
