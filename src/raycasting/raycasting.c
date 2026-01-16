/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:28:43 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/16 23:24:13 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/raycasting.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= W || y >= H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	step_and_side(t_game *g, t_ray *r)
{
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (g->player.x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - g->player.x) * r->delta_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->player.y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - g->player.y) * r->delta_y;
	}
}

void	dda(t_game *g, t_ray *r)
{
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (g->data->map[r->map_y][r->map_x] != '0')
		{
			r->hit = 1;
		}
	}
}

void	draw_column(t_game *g, t_ray *r, int x)
{
	int	line_h;
	int	draw_start;
	int	draw_end;
	int	y;

	if (r->side == 0)
		r->perp_dist = r->side_dist_x - r->delta_x;
	else
		r->perp_dist = r->side_dist_y - r->delta_y;
	line_h = (int)(H / r->perp_dist);
	draw_start = -line_h / 2 + H / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_h / 2 + H / 2;
	if (draw_end >= H)
		draw_end = H - 1;
	y = 0;
	while (y < draw_start)
	{
		put_pixel(&g->img, x, y, g->data->celling_color);
		y++;
	}
	while (y < draw_end)
	{
		put_pixel(&g->img, x, y, r->side ? 0x00ff44 : 0xff1100);
		y++;
	}
	while (y < H)
	{
		put_pixel(&g->img, x, y, g->data->floor_color);
		y++;
	}
}

int	render(void *ptr)
{
	int		x;
	t_game	*game;
	t_ray	r;

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
	game->is_game_running = false;
	return (0);
}
