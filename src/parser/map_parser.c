/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:34:34 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 01:43:39 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	free_grdon_map(t_map_list *head, t_map *map, int ind)
{
	if (head)
		free_map_lst(head);
	if (map)
		free_map(map, ind);
	ft_putstr_fd(GRDON_MAP, 2);
}

void	replace_map_spaces(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
				map->map[i][j] = '0';
			++j;
		}
		++i;
	}
}

t_map	*list_to_map(t_map_list *head, int height)
{
	int			i;
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
		if (ft_strcmp(temp->row, "") == 0 && check_map_empty_lines(temp))
			return (free_grdon_map(head, map, i), NULL);
		map->map[i] = ft_strdup(temp->row);
		if (!map->map[i])
			return (free_grdon_map(head, map, i), NULL);
		if (map->max_width < ft_strlen(map->map[i]))
			map->max_width = ft_strlen(map->map[i]);
		temp = temp->next;
	}
	map->map[height] = NULL;
	replace_map_spaces(map);
	return (free_map_lst(head), map);
}

int	parse_map(t_config *config, char **first_line, int fd)
{
	int			size;
	char		*line;
	t_map_list	*head;
	t_map_list	*temp;

	if (!textures_are_complete(config) || !colors_are_complete(config))
		return (ft_putstr_fd(WRONG_ORDER_ERR, 2), 0);
	head = new_node(first_line);
	if (!head)
		return (0);
	size = 1;
	temp = head;
	line = get_next_line(fd);
	while (line)
	{
		temp->next = new_node(&line);
		temp = temp->next;
		free(line);
		line = get_next_line(fd);
		++size;
	}
	config->map = list_to_map(head, size);
	if (!config->map)
		return (free(line), 0);
	return (free(line), 1);
}
