/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:48:36 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/27 20:53:47 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->texture[0].img);
	mlx_destroy_image(game->mlx, game->texture[1].img);
	mlx_destroy_image(game->mlx, game->texture[2].img);
	mlx_destroy_image(game->mlx, game->texture[3].img);
	if (game->mlx)
	{
		free(game->mlx);
		game->mlx = NULL;
	}
	free_data(game->data);
}
