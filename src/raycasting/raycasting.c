/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:28:43 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/27 17:07:52 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	pick_texture(t_ray *ray, t_door *door)
{
	ray->wall_dir = TEX_DOOR;
	if (ray->side == 0)
	{
		if (!door)
		{
			ray->wall_dir = TEX_EAST;
			if (ray->raydir_x < 0)
				ray->wall_dir = TEX_WEST;
		}
	}
	else
	{
		if (!door)
		{
			ray->wall_dir = TEX_SOUTH;
			if (ray->raydir_y < 0)
				ray->wall_dir = TEX_NORTH;
		}
	}
}

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
	t_door			*door;

	door = get_door_at(g, r->map_x, r->map_y);
	if (door && door->open)
		return ;
	pick_texture(r, door);
	if (r->side == 0)
	{
		r->perp_dist = r->side_dist_x - r->delta_x;
		draw.wall_x = g->player.y + r->perp_dist * r->raydir_y;
	}
	else
	{
		r->perp_dist = r->side_dist_y - r->delta_y;
		draw.wall_x = g->player.x + r->perp_dist * r->raydir_x;
	}
	calc_and_display(g, r, x, draw);
}

int	render(void *ptr)
{
	int				x;
	t_ray			r;
	t_game			*game;
	struct timeval	current_time;
	long			current_ms;

	x = -1;
	game = (t_game *)ptr;
	gettimeofday(&current_time, NULL);
	current_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	if (current_ms - game->last_frame_time < (1000 / TARGET_FPS))
		return (0);
	game->last_frame_time = current_ms;
	ft_memset(game->img.addr, 0, H * game->img.line_len);
	while (++x < W)
	{
		(init_ray(game, &r, x), step_and_side(game, &r));
		dda(game, &r);
		draw_column(game, &r, x);
		game->zbuffer[x] = r.perp_dist;
	}
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	(handle_movement(game), update_spirits(game), render_spirits(game));
	return (render_minimap(game), 0);
}
