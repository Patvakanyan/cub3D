/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:31:07 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/27 02:40:25 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

char	*skip_spaces(char *src)
{
	int	i;

	i = 0;
	while (src[i] && (src[i] == ' ' || src[i] == '\t'))
		++i;
	return (src + i);
}

static int	parse_colors(char *src, int *clr)
{
	int		i;
	int		val[3];
	char	**nums;

	src = skip_spaces(src);
	if (*src == 'F' || *src == 'C')
		src++;
	src = skip_spaces(src);
	nums = ft_split(src, ',');
	if (!nums)
		return (0);
	if (split_len(nums) != 3)
		return (ft_putstr_fd(COLOR_ERR_1, 2), free_split(nums), 0);
	i = 0;
	while (i < 3)
	{
		val[i] = ft_atoi(skip_spaces(nums[i]));
		if (val[i] < 0 || val[i] > 255)
			return (ft_putstr_fd(COLOR_ERR_2, 2), free_split(nums), 0);
		++i;
	}
	(*clr) = (val[0] << 16) | (val[1] << 8) | val[2];
	free_split(nums);
	return (1);
}

int	safe_place(t_config *config, char **spl, char config_name)
{
	char	*target;

	if (!colors_not_set(config) && !colors_are_complete(config))
		return (free_split(spl), ft_putstr_fd(WRONG_ORDER_ERR, 2), 0);
	if (split_len(spl) != 2)
		return (free_split(spl), ft_putstr_fd(PATH_ELEM_COUNT_ERR, 2), 0);
	trim_newlines(&spl[1]);
	target = ft_strdup(spl[1]);
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
	else if (config_name == 'D')
		config->door = target;
	else if (config_name == 'C')
		config->spirit = target;
	free_split(spl);
	return (1);
}

int	assign_color(t_config *config, char *src)
{
	if (!textures_not_set(config) && !textures_are_complete(config))
		return (ft_putstr_fd(WRONG_ORDER_ERR, 2), 0);
	while (*src && (*src == ' ' || *src == '\t'))
		++src;
	if (*src == 'F')
	{
		if (!parse_colors(src + 1, &config->floor))
			return (0);
	}
	else if (*src == 'C')
	{
		if (!parse_colors(src + 1, &config->ceiling))
			return (0);
	}
	return (1);
}

int	place_config(t_config *configs, char *src)
{
	char	**spl;

	spl = ft_split(src, ' ');
	if (!spl || !spl[1])
		return (0);
	if (ft_strcmp(spl[0], "C") == 0 && configs->ceiling == -1)
		return (free_split(spl), assign_color(configs, src));
	if (ft_strcmp(spl[0], "F") == 0 && configs->floor == -1)
		return (free_split(spl), assign_color(configs, src));
	if (ft_strcmp(spl[0], "NO") == 0 && !configs->north)
		return (safe_place(configs, spl, 'N'));
	if (ft_strcmp(spl[0], "SO") == 0 && !configs->south)
		return (safe_place(configs, spl, 'S'));
	if (ft_strcmp(spl[0], "EA") == 0 && !configs->east)
		return (safe_place(configs, spl, 'E'));
	if (ft_strcmp(spl[0], "WE") == 0 && !configs->west)
		return (safe_place(configs, spl, 'W'));
	if (ft_strcmp(spl[0], "DO") == 0 && !configs->door)
		return (safe_place(configs, spl, 'D'));
	if (ft_strcmp(spl[0], "SP") == 0 && !configs->spirit)
		return (safe_place(configs, spl, 'C'));
	if (check_first_arg(spl[0]))
		return (ft_putstr_fd(DUP_ERROR, 2), ft_putstr_fd(spl[0], 2),
				ft_putstr_fd("'\n", 2), free_split(spl), 0);
	return (free_split(spl), 0);
}
