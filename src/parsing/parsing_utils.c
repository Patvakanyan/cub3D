/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:19:48 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/18 19:17:54 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

char	*clean_new_line(char *row)
{
	char	*tmp;

	if (!row || !*row)
		return (NULL);
	tmp = ft_strrchr(row, '\n');
	if (tmp)
		return (ft_substr(row, 0, tmp - row));
	return (ft_strdup(row));
}

t_map	*new_node(char *tmp)
{
	t_map	*new;
	char	*cleaned;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	cleaned = clean_new_line(tmp);
	new->type = get_type(cleaned);
	if (new->type != MAP)
		new->row = ft_split(cleaned, ' ');
	else
		new->row = ft_split(cleaned, '\0');
	free(cleaned);
	new->next = NULL;
	return (new);
}

void	free_list(t_map *list)
{
	t_map	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list->next;
		free_split(list->row);
		free(list);
		list = tmp;
	}
}

static t_map	*add_node(t_map **list, t_map *tail, char *row)
{
	t_map	*new;

	new = new_node(row);
	if (!new)
		return (NULL);
	if (!*list)
		*list = new;
	else
		tail->next = new;
	return (new);
}

t_map	*give_list_map(int fd)
{
	t_map	*list;
	t_map	*tail;
	char	*row;

	list = NULL;
	row = get_next_line(fd);
	while (row && (*row == '\n' || chek_row(row)))
	{
		free(row);
		row = get_next_line(fd);
	}
	while (row)
	{
		tail = add_node(&list, tail, row);
		if (!tail && list)
			return (free_list(list), NULL);
		free(row);
		row = get_next_line(fd);
		while (row && (*row == '\n' || chek_row(row)) && (free(row), 1))
			row = get_next_line(fd);
	}
	return (list);
}
