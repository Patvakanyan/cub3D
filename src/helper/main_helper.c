/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:48:36 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 13:19:08 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	get_player_dir(t_game *game, int i, int j)
{
	char	c;
	double	fov;

	c = game->data->map[i][j];
	fov = 0.66;
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	game->player.plane_x = -game->player.dir_y * fov;
	game->player.plane_y = game->player.dir_x * fov;
}

bool	get_player_pos(t_game *game, double *x, double *y)
{
	int	i;
	int	j;

	i = 0;
	while (game->data->map[i])
	{
		j = 0;
		while (game->data->map[i][j])
		{
			if (is_player_char(game->data->map[i][j]))
			{
				get_player_dir(game, i, j);
				game->data->map[i][j] = '0';
				*x = (double)j;
				*y = (double)i;
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
