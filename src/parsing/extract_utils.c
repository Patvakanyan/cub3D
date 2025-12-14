/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:13:50 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/14 19:14:15 by apatvaka         ###   ########.fr       */
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
			return (true);
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

bool	check_map_line(char **line)
{
	int	i;
	int	j;

	i = -1;
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
