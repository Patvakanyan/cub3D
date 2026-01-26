/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:57:36 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/26 21:21:10 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	free_bonus_imgs(t_game *game)
{
	if (game->texture[4].img != NULL)
	{
		mlx_destroy_image(game->mlx, game->texture[4].img);
		game->texture[4].img = NULL;
	}
	if (game->texture[5].img != NULL)
	{
		mlx_destroy_image(game->mlx, game->texture[5].img);
		game->texture[5].img = NULL;
	}
}

void	free_doors(t_door *head)
{
	t_door	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	head = NULL;
}

void	free_spirits(t_spirit *head)
{
	t_spirit	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	head = NULL;
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
		free_bonus_imgs(game);
	}
	if (game->mlx)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	close(game->fd);
	free_configs(game->config);
}
