/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:23:52 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 20:54:28 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

bool	set_bonus_texture_properties(t_game *game)
{
	if (game->config->door)
	{
		game->texture[4].addr = mlx_get_data_addr(game->texture[4].img,
				&game->texture[4].bpp, &game->texture[4].line_len,
				&game->texture[4].endian);
		if (!game->texture[4].addr)
			return (false);
	}
	if (game->config->spirit)
	{
		game->texture[5].addr = mlx_get_data_addr(game->texture[5].img,
				&game->texture[5].bpp, &game->texture[5].line_len,
				&game->texture[5].endian);
		if (!game->texture[5].addr)
			return (false);
	}
	return (true);
}

bool	init_bonus_textures(t_game *game)
{
	if (game->config->door)
	{
		game->texture[4].img = mlx_xpm_file_to_image(game->mlx,
				game->config->door, &game->texture[4].width,
				&game->texture[4].height);
		if (!game->texture[4].img)
			return (false);
	}
	if (game->config->spirit)
	{
		game->texture[5].img = mlx_xpm_file_to_image(game->mlx,
				game->config->spirit, &game->texture[5].width,
				&game->texture[5].height);
		if (!game->texture[5].img)
			return (false);
	}
	return (set_bonus_texture_properties(game));
}
