/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:44:47 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/26 04:25:11 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init.h"

bool	init_player(t_game *game)
{
	if (!game)
		return (false);
	game->player.move_speed = 0.1;
	game->player.rot_speed = 0.1;
	return (true);
}

static bool	set_texture_properties(t_game *game)
{
	game->texture[0].addr = mlx_get_data_addr(game->texture[0].img,
			&game->texture[0].bpp, &game->texture[0].line_len,
			&game->texture[0].endian);
	game->texture[1].addr = mlx_get_data_addr(game->texture[1].img,
			&game->texture[1].bpp, &game->texture[1].line_len,
			&game->texture[1].endian);
	game->texture[2].addr = mlx_get_data_addr(game->texture[2].img,
			&game->texture[2].bpp, &game->texture[2].line_len,
			&game->texture[2].endian);
	game->texture[3].addr = mlx_get_data_addr(game->texture[3].img,
			&game->texture[3].bpp, &game->texture[3].line_len,
			&game->texture[3].endian);
	game->texture[4].addr = mlx_get_data_addr(game->texture[4].img,
			&game->texture[4].bpp, &game->texture[4].line_len,
			&game->texture[4].endian);
	if (!game->texture[0].addr || !game->texture[1].addr
		|| !game->texture[2].addr || !game->texture[3].addr
		|| !game->texture[4].addr)
		return (ft_putstr_fd("Error: Failed to get texture data.\n", 2), false);
	return (true);
}

static bool	init_img(t_game *game)
{
	game->texture[0].img = mlx_xpm_file_to_image(game->mlx,
			game->config->west, &game->texture[0].width,
			&game->texture[0].height);
	game->texture[1].img = mlx_xpm_file_to_image(game->mlx,
			game->config->east, &game->texture[1].width,
			&game->texture[1].height);
	game->texture[2].img = mlx_xpm_file_to_image(game->mlx,
			game->config->north, &game->texture[2].width,
			&game->texture[2].height);
	game->texture[3].img = mlx_xpm_file_to_image(game->mlx,
			game->config->south, &game->texture[3].width,
			&game->texture[3].height);
	game->texture[4].img = mlx_xpm_file_to_image(game->mlx,
			game->config->door, &game->texture[4].width,
			&game->texture[4].height);
	if (!game->texture[0].img || !game->texture[1].img
		|| !game->texture[2].img || !game->texture[3].img
		|| !game->texture[4].img)
		return (false);
	return (set_texture_properties(game));
}

bool	init_game(t_game *game)
{
	if (!init_player(game))
		return (false);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	game->win = mlx_new_window(game->mlx, W, H, "Cub3D");
	if (!game->win)
		return (free(game->mlx), false);
	game->img.img = mlx_new_image(game->mlx, W, H);
	if (!game->img.img)
		return (free(game->win), free(game->mlx), false);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	return (init_img(game));
}

void	init_ray(t_game *g, t_ray *r, int x)
{
	r->camera_x = 2.0 * x / (double)W - 1.0;
	r->raydir_x = g->player.dir_x + g->player.plane_x * r->camera_x;
	r->raydir_y = g->player.dir_y + g->player.plane_y * r->camera_x;
	r->map_x = (int)g->player.x;
	r->map_y = (int)g->player.y;
	r->delta_x = fabs(1 / r->raydir_x);
	r->delta_y = fabs(1 / r->raydir_y);
	r->side = 0;
	r->hit = 0;
}
