/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:28:43 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/13 18:15:34 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	get_wall_texture(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->raydir_x > 0)
			return (2); // WE
		return (3); // EA
	}
	else
	{
		if (r->raydir_y > 0)
			return (0); // NO
		return (1); // SO
	}
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= W || y >= H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
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
	r->hit = 0;
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
			r->hit = 1;
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
	draw_end = line_h / 2 + H / 2;
	y = draw_start;
	while (y < draw_end)
	{
		put_pixel(&g->img, x, y, r->side ? 0x00ff44 : 0x00ff44);
		y++;
	}
}

 int	render(t_game *game)
{
	int		x;
	t_ray	r;

	x = 0;
	while (x < W)
	{
		init_ray(game, &r, x);
		step_and_side(game, &r);
		dda(game, &r);
		draw_column(game, &r, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

