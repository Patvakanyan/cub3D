/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:34:34 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 15:06:23 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

t_map	*list_to_map(t_map_list *head, int height)
{
	int			i;
	int			len;
	t_map		*map;
	t_map_list	*temp;

	if (height <= 0 || !head)
		return (NULL);
	map = init_map(height);
	if (!map)
		return (free_map_lst(head), NULL);
	i = -1;
	temp = head;
	while (temp && ++i < height)
	{
		map->map[i] = ft_strdup(temp->row);
		if (!map->map[i])
			return (free_map_lst(head), free_map(map, i), NULL);
		len = ft_strlen(map->map[i]);
		if (map->max_width < len)
			map->max_width = len;
		temp = temp->next;
	}
	map->map[height] = NULL;
	return (free_map_lst(head), map);
}

int	parse_map(t_config *config, char **first_line, int fd)
{
	char		*line;
	t_map_list	*head;
	t_map_list	*temp;
	t_map_list	*node;
	int			size;

	if (!textures_are_complete(config) || !colors_are_complete(config))
		return (ft_putstr_fd(WRONG_ORDER_ERR, 2), 0);
	head = new_node(first_line);
	if (!head)
		return (0);
	size = 1;
	temp = head;
	line = get_next_line(fd);
	while (line && *line != '\n')
	{
		node = new_node(&line);
		free(line);
		temp->next = node;
		temp = node;
		line = get_next_line(fd);
		++size;
	}
	config->map = list_to_map(head, size);
	return (free(line), 1);
}
