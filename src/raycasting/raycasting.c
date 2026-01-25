/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:28:43 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/25 20:09:46 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

static void	display(t_game *g, t_ray *r, int x, t_draw_configs draw)
{
	int	y;

	y = -1;
	while (++y < draw.draw_start)
		put_pixel(&g->img, x, y, g->config->ceiling);
	while (y < draw.draw_end)
	{
		draw.tex_y = (int)draw.tex_pos & (g->texture[r->wall_dir].height - 1);
		draw.texture_color = get_tex_color(&g->texture[r->wall_dir],
				draw.tex_x, draw.tex_y);
		put_pixel(&g->img, x, y, draw.texture_color);
		draw.tex_pos += draw.step;
		y++;
	}
	while (++y < H)
		put_pixel(&g->img, x, y, g->config->floor);
}

static void	calc_and_display(t_game *g, t_ray *r, int x, t_draw_configs draw)
{
	draw.wall_x -= floor(draw.wall_x);
	draw.line_h = H / r->perp_dist;
	draw.draw_start = -draw.line_h / 2 + H / 2;
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	draw.draw_end = draw.line_h / 2 + H / 2;
	if (draw.draw_end >= H)
		draw.draw_end = H - 1;
	draw.tex_x = (draw.wall_x * g->texture[r->wall_dir].width);
	draw.step = 1.0 * g->texture[r->wall_dir].height / draw.line_h;
	draw.tex_pos = (draw.draw_start - H / 2 + draw.line_h / 2) * draw.step;
	display(g, r, x, draw);
}

void	draw_column(t_game *g, t_ray *r, int x)
{
	t_draw_configs	draw;

	if (r->side == 0)
	{
		r->wall_dir = TEX_EAST;
		if (r->raydir_x < 0)
			r->wall_dir = TEX_WEST;
		r->perp_dist = r->side_dist_x - r->delta_x;
		draw.wall_x = g->player.y + r->perp_dist * r->raydir_y;
	}
	else
	{
		r->wall_dir = TEX_SOUTH;
		if (r->raydir_y < 0)
			r->wall_dir = TEX_NORTH;
		r->perp_dist = r->side_dist_y - r->delta_y;
		draw.wall_x = g->player.x + r->perp_dist * r->raydir_x;
	}
	calc_and_display(g, r, x, draw);
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
