/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:57:36 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/21 11:35:22 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.h"

void	free_split_all(char ***split)
{
	int	i;

	i = -1;
	if (!split)
		return ;
	while (split[++i])
		free_split(split[i]);
	free(split);
	split = NULL;
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_split(data->map);
	if (data->wall)
		free_split_all(data->wall);
	free(data);
	data = NULL;
}

void	free_list(t_map *list)
{
	t_map	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list->next;
		free_split(list->row);
		free(list);
		list = tmp;
	}
}

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	if (!game)
		return ;
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	while (++i < 4)
	{
		if (game->texture[i].img)
		{
			mlx_destroy_image(game->mlx, game->texture[i].img);
			game->texture[i].img = NULL;
		}
	}
	if (game->mlx)
	{
		free(game->mlx);
		game->mlx = NULL;
	}
	free_data(game->data);
}
