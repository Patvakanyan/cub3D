/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:31:07 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 15:06:40 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

int	safe_place(t_config *config, char **src, char config_name)
{
	char	*target;

	if (!colors_not_set(config) && !colors_are_complete(config))
		return (ft_putstr_fd(WRONG_ORDER_ERR, 2), 0);
	trim_newlines(src);
	target = ft_strdup(*src);
	if (!target)
		return (0);
	if (config_name == 'N')
		config->north = target;
	else if (config_name == 'S')
		config->south = target;
	else if (config_name == 'E')
		config->east = target;
	else if (config_name == 'W')
		config->west = target;
	return (1);
}

int	assign_color(t_config *config, char *src, char c_f)
{
	int		r;
	int		g;
	int		b;
	char	**split;

	if (!textures_not_set(config) && !textures_are_complete(config))
		return (ft_putstr_fd(WRONG_ORDER_ERR, 2), 0);
	split = ft_split(src, ',');
	if (!split)
		return (free_split(split), 0);
	if (split_len(split) != 3)
		return (free_split(split), ft_putstr_fd(COLOR_ERR_1, 2), 0);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_putstr_fd(COLOR_ERR_2, 2);
		return (free_split(split), ft_putstr_fd(HINT, 2), 0);
	}
	if (c_f == 'C')
		config->ceiling = (r << 16) | (g << 8) | b;
	else if (c_f == 'F')
		config->floor = (r << 16) | (g << 8) | b;
	return (free_split(split), 1);
}

int	place_config(t_config *configs, char **spl)
{
	if (!spl[1])
		return (0);
	if (ft_strcmp(spl[0], "C") == 0 && configs->ceiling == -1)
		return (assign_color(configs, spl[1], 'C'));
	if (ft_strcmp(spl[0], "F") == 0 && configs->floor == -1)
		return (assign_color(configs, spl[1], 'F'));
	if (ft_strcmp(spl[0], "NO") == 0 && !configs->north)
		return (safe_place(configs, &spl[1], 'N'));
	if (ft_strcmp(spl[0], "SO") == 0 && !configs->south)
		return (safe_place(configs, &spl[1], 'S'));
	if (ft_strcmp(spl[0], "EA") == 0 && !configs->east)
		return (safe_place(configs, &spl[1], 'E'));
	if (ft_strcmp(spl[0], "WE") == 0 && !configs->west)
		return (safe_place(configs, &spl[1], 'W'));
	if (check_first_arg(spl[0]))
	{
		ft_putstr_fd(DUP_ERROR, 2);
		ft_putstr_fd(spl[0], 2);
		ft_putstr_fd("'\n", 2);
	}
	return (0);
}
