/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spirit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:36:58 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 20:19:21 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	calculate(t_draw_spirit *d)
{
	d->sprite_src_x = (int)((W / 2) * (1 + d->transform_x / d->transform_y));
	d->sprite_h = abs((int)(H / d->transform_y));
	d->sprite_w = d->sprite_h;
	d->draw_start_y = -d->sprite_h / 2 + H / 2;
	d->draw_end_y = d->sprite_h / 2 + H / 2;
	d->draw_start_x = -d->sprite_w / 2 + d->sprite_src_x;
	d->draw_end_x = d->sprite_w / 2 + d->sprite_src_x;
	if (d->draw_start_y < 0)
		d->draw_start_y = 0;
	if (d->draw_end_y >= H)
		d->draw_end_y = H - 1;
	if (d->draw_start_x < 0)
		d->draw_start_x = 0;
	if (d->draw_end_x >= W)
		d->draw_end_x = W - 1;
}

void	move_spirit_towards_player(t_game *g, t_spirit *s)
{
	double	dx;
	double	dy;
	double	len;
	double	new_x;
	double	new_y;

	if (!spirit_can_see_player(g, s))
		return ;
	dx = g->player.x - s->x;
	dy = g->player.y - s->y;
	len = sqrt(dx * dx + dy * dy);
	if (len < 0.3)
		return ;
	dx /= len;
	dy /= len;
	new_x = s->x + dx * s->speed;
	new_y = s->y + dy * s->speed;
	if (can_move(g, new_x, new_y))
	{
		s->x = new_x;
		s->y = new_y;
	}
}

static void	draw_spirit(t_game *g, t_spirit *s)
{
	t_draw_spirit	d;

	d.sprite_x = s->x - g->player.x;
	d.sprite_y = s->y - g->player.y;
	d.inv_det = 1.0 / (g->player.plane_x * g->player.dir_y
			- g->player.dir_x * g->player.plane_y);
	d.transform_x = d.inv_det * (g->player.dir_y * d.sprite_x
			- g->player.dir_x * d.sprite_y);
	d.transform_y = d.inv_det * (-g->player.plane_y * d.sprite_x
			+ g->player.plane_x * d.sprite_y);
	if (d.transform_y <= 0)
		return ;
	calculate(&d);
	d.x = d.draw_start_x;
	while (d.x < d.draw_end_x)
	{
		d.tex_x = (d.x - d.draw_start_x)
			* g->texture[TEX_SPIRIT].width / d.sprite_w;
		if (d.transform_y < g->zbuffer[d.x])
			draw_spirit_pixels(g, d);
		d.x++;
	}
}

void	render_spirits(t_game *game)
{
	t_spirit	*s;

	s = game->config->spirits;
	while (s)
	{
		draw_spirit(game, s);
		s = s->next;
	}
}
