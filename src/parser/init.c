/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:47:03 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 16:44:51 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

t_map	*init_map(int height)
{
	t_map	*map;

	if (height <= 0)
		return (ft_putstr_fd(ALLOC_ERR, 2), NULL);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (ft_putstr_fd(ALLOC_ERR, 2), NULL);
	map->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map->map)
	{
		free(map);
		return (ft_putstr_fd(ALLOC_ERR, 2), NULL);
	}
	map->height = height;
	map->max_width = -1;
	return (map);
}

t_config	*init_configs(void)
{
	t_config	*configs;

	configs = (t_config *)malloc(sizeof(t_config));
	if (!configs)
		return (NULL);
	configs->north = NULL;
	configs->south = NULL;
	configs->east = NULL;
	configs->west = NULL;
	configs->ceiling = -1;
	configs->floor = -1;
	configs->map = NULL;
	return (configs);
}

t_map_list	*new_node(char **val)
{
	t_map_list	*node;

	node = (t_map_list *)malloc(sizeof(t_map_list));
	if (!node)
		return (NULL);
	trim_newlines(val);
	node->row = ft_strdup(*val);
	node->next = NULL;
	return (node);
}
