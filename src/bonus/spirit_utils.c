/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spirit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:15:19 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 20:19:15 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	add_spirit(t_spirit **head, int x, int y)
{
	t_spirit	*new;

	new = malloc(sizeof(t_spirit));
	if (!new)
		return (ft_putstr_fd(ALLOC_ERR, 2), 0);
	new->x = x + 0.5;
	new->y = y + 0.5;
	new->speed = 0.02;
	new->next = *head;
	*head = new;
	return (1);
}

int	spirit_can_see_player(t_game *g, t_spirit *s)
{
	t_spirit_configs	conf;

	conf.dx = g->player.x - s->x;
	conf.dy = g->player.y - s->y;
	conf.dist = sqrt(conf.dx * conf.dx + conf.dy * conf.dy);
	conf.dx /= conf.dist;
	conf.dy /= conf.dist;
	conf.step = 0.05;
	conf.x = s->x;
	conf.y = s->y;
	while (conf.dist > 0)
	{
		if (!can_move(g, conf.x, conf.y))
			return (0);
		conf.x += conf.dx * conf.step;
		conf.y += conf.dy * conf.step;
		conf.dist -= conf.step;
	}
	return (1);
}

void	update_spirits(t_game *game)
{
	t_spirit	*s;

	s = game->config->spirits;
	while (s)
	{
		move_spirit_towards_player(game, s);
		s = s->next;
	}
}

void	draw_spirit_pixels(t_game *g, t_draw_spirit d)
{
	int	y;
	int	tex_y;
	int	color;

	y = d.draw_start_y;
	while (y < d.draw_end_y)
	{
		tex_y = (y - d.draw_start_y)
			* g->texture[TEX_SPIRIT].height / d.sprite_h;
		color = get_tex_color(&g->texture[TEX_SPIRIT], d.tex_x, tex_y);
		if ((color & 0x00FFFFFF) != 0)
			put_pixel(&g->img, d.x, y, color);
		y++;
	}
}
