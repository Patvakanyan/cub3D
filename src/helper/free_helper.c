/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:57:36 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/23 22:09:53 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tools.h"

void	free_game(t_game *game)
{
	int i;

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
		mlx_destroy_image(game->mlx, game->img.img);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free_configs(game->config);
}
