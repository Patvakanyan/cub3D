/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:00:48 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 15:06:11 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

int	textures_not_set(t_config *c)
{
	return (!c->north && !c->south && !c->east && !c->west && !c->map);
}

int	colors_not_set(t_config *c)
{
	return (c->ceiling == -1 && c->floor == -1 && !c->map);
}

int	textures_are_complete(t_config *c)
{
	return (c->north && c->south && c->east && c->west && !c->map);
}

int	colors_are_complete(t_config *c)
{
	return (c->ceiling != -1 && c->floor != -1 && !c->map);
}

int	check_first_arg(char *arg)
{
	if (!arg)
		return (0);
	if ((ft_strcmp(arg, "C") == 0) || (ft_strcmp(arg, "F") == 0)
		|| (ft_strcmp(arg, "NO") == 0) || (ft_strcmp(arg, "SO") == 0)
		|| (ft_strcmp(arg, "EA") == 0) || (ft_strcmp(arg, "WE") == 0))
		return (1);
	ft_putstr_fd(WRONG_CONFIG, 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("'\n", 2);
	return (0);
}
