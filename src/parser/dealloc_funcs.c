/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:00:29 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 15:06:15 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	free_configs(t_config *configs)
{
	free(configs->north);
	free(configs->south);
	free(configs->east);
	free(configs->west);
	if (configs->map)
		free_map(configs->map, configs->map->height);
	free(configs);
}

void	free_map(t_map *map, int size)
{
	if (!map)
		return ;
	while (size-- > 0)
		free(map->map[size]);
	free(map->map);
	free(map);
}

void	free_map_lst(t_map_list *head)
{
	t_map_list	*temp;
	t_map_list	*nxt;

	if (!head)
		return ;
	temp = head;
	while (temp)
	{
		nxt = temp->next;
		free(temp->row);
		free(temp);
		temp = nxt;
	}
}

void	free_split(char **split)
{
	size_t	i;

	if (!split || !split[0])
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
	split = NULL;
}

void	free_stuff(t_config *config, char *line, char **split)
{
	if (line)
		free(line);
	if (split)
		free_split(split);
	if (config)
		free_configs(config);
	get_next_line(-1);
}
