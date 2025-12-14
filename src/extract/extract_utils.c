/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:13:50 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/14 19:43:49 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

char	*ft_splitdup(char **str)
{
	char	*ret;
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	ret = ft_strdup("");
	while (str[++i])
	{
		tmp = ft_strjoin(ret, str[i]);
		if (ret)
			free(ret);
		ret = tmp;
	}
	return (ret);
}

bool	check_single_parameter(t_map *tmp, char *param, t_type type)
{
	t_map	*start;

	start = tmp;
	start = start->next;
	if (start == NULL)
		return (true);
	while (start)
	{
		if (start->type == type && ft_strcmp(start->row[0], param) == 0)
			return (ft_putstr_fd("has duplicates\n", 2), true);
		start = start->next;
	}
	return (false);
}

int	get_map_size(t_map *map)
{
	int		counter;
	t_map	*tmp;

	counter = 0;
	tmp = map;
	if (map->type != MAP)
		return (0);
	while (tmp)
	{
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}

int	get_size_of_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

bool	check_first_last_row(char *row)
{
	int	j;

	j = -1;
	while (row && row[++j])
	{
		if (row[j] != '1' && row[j] != ' ')
			return (false);
	}
	return (true);
}

bool	check_map_line(char **line)
{
	int	i;
	int	j;
	int	size;

	size = get_size_of_split(line);
	i = -1;
	if (!check_first_last_row(line[0]) || !check_first_last_row(line[size - 1]))
		return (false);
	while (line[++i])
	{
		j = -1;
		while (line[i][++j])
			if (line[i][j] != '1' && line[i][j] != ' ' && line[i][j] != 'N'
				&& line[i][j] != 'S' && line[i][j] != 'E' && line[i][j] != 'W'
				&& line[i][j] != '0')
				return (false);
	}
	return (true);
}
