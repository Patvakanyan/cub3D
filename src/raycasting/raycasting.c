/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:28:43 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 16:41:31 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

void	draw_column(t_game *g, t_ray *r, int x)
{
	int		line_h;
	int		draw_start;
	int		texture_color;
	int		draw_end;
	int		y;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	tex_pos;
	double	step;

	if (r->side == 0)
	{
		if (r->raydir_x < 0)
			r->wall_dir = 0;
		else
			r->wall_dir = 1;
		r->perp_dist = r->side_dist_x - r->delta_x;
		wall_x = g->player.y + r->perp_dist * r->raydir_y;
	}
	else
	{
		if (r->raydir_y < 0)
			r->wall_dir = 2;
		else
			r->wall_dir = 3;
		r->perp_dist = r->side_dist_y - r->delta_y;
		wall_x = g->player.x + r->perp_dist * r->raydir_x;
	}
	wall_x -= floor(wall_x);
	line_h = (int)(H / r->perp_dist);
	draw_start = -line_h / 2 + H / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_h / 2 + H / 2;
	if (draw_end >= H)
		draw_end = H - 1;
	tex_x = (int)(wall_x * g->texture[r->wall_dir].width);
	step = 1.0 * g->texture[r->wall_dir].height / line_h;
	tex_pos = (draw_start - H / 2 + line_h / 2) * step;
	y = 0;
	while (y < draw_start)
	{
		put_pixel(&g->img, x, y, g->config->ceiling);
		y++;
	}
	while (y < draw_end)
	{
		tex_y = (int)tex_pos & (g->texture[r->wall_dir].height - 1);
		texture_color = get_tex_color(&g->texture[r->wall_dir], tex_x, tex_y);
		put_pixel(&g->img, x, y, texture_color);
		tex_pos += step;
		y++;
	}
	while (y < H)
	{
		put_pixel(&g->img, x, y, g->config->floor);
		y++;
	}
}

int	render(void *ptr)
{
	int		x;
	t_ray	r;
	t_game	*game;

	x = 0;
	game = (t_game *)ptr;
	ft_memset(game->img.addr, 0, H * game->img.line_len);
	while (x < W)
	{
		init_ray(game, &r, x);
		step_and_side(game, &r);
		dda(game, &r);
		draw_column(game, &r, x);
		x++;
	}
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	move_character(game, game->move_flag);
	return (0);
}
