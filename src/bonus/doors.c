/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:01:17 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 04:26:32 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bonus.h"

int	can_move(t_game *game, double new_x, double new_y)
{
	int		map_x;
	int		map_y;
	char	cell;
	t_door	*door;

	map_x = (int)new_x;
	map_y = (int)new_y;
	cell = game->config->map->map[map_y][map_x];
	if (cell == '1')
		return (0);
	if (!game->config->doors)
		return (1);
	door = game->config->doors;
	while (door)
	{
		if (door->x == map_x && door->y == map_y && !door->open)
			return (0);
		door = door->next;
	}
	return (1);
}

int	add_door(t_door **head, int x, int y)
{
	t_door	*new_door;
	t_door	*tmp;

	new_door = malloc(sizeof(t_door));
	if (!new_door)
		return (ft_putstr_fd(ALLOC_ERR, 2), 0);
	new_door->x = x;
	new_door->y = y;
	new_door->open = 0;
	new_door->next = NULL;
	if (!*head)
		*head = new_door;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_door;
	}
	return (1);
}

int	parse_doors_line(t_door **doors, const char *row, int y)
{
	int	x;

	if (!row)
		return (1);
	x = 0;
	while (row[x])
	{
		if (row[x] == 'D')
		{
			if (!add_door(doors, x, y))
				return (0);
		}
		++x;
	}
	return (1);
}

static int	is_near_player(int player_x, int player_y, t_door *door)
{
	if ((door->x == player_x && door->y == player_y)
		|| (door->x == player_x + 1 && door->y == player_y)
		|| (door->x == player_x - 1 && door->y == player_y)
		|| (door->x == player_x && door->y == player_y + 1)
		|| (door->x == player_x && door->y == player_y - 1))
		return (1);
	return (0);
}

void	interact_door(t_game *game)
{
	t_door	*door;
	int		player_x;
	int		player_y;

	player_x = (int)game->player.x;
	player_y = (int)game->player.y;
	door = game->config->doors;
	while (door != NULL)
	{
		if (is_near_player(player_x, player_y, door))
		{
			door->open = !door->open;
			if (door->open)
				game->config->map->map[door->y][door->x] = '0';
			else
				game->config->map->map[door->y][door->x] = 'D';
			break ;
		}
		door = door->next;
	}
}
