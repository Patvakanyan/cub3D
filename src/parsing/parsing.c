/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:17:14 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/11 19:23:03 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	is_ceiling_floor(char *row)
{
	char	**tmp;

	tmp = ft_split(row, ' ');
	if (!ft_strcmp(tmp[0], "F") || !ft_strcmp(tmp[0], "C"))
		return (free_split(tmp), 1);
	free_split(tmp);
	return (0);
}

int	is_map_row(char *row)
{
	int		i;
	bool	flag;

	flag = true;
	i = -1;
	while (row[++i])
	{
		if (row[i] != '1' && row[i] != '0' && row[i] != ' ' && row[i] != 'N'
			&& row[i] != 'S' && row[i] != 'W' && row[i] != 'E')
			flag = false;
	}
	i = -1;
	while (row[++i])
		if (row[i] != ' ')
			break ;
	if (row[i] != '1' || row[ft_strlen(row) - 1] != '1')
		flag = false;
	return (flag);
}

int	get_type(char *tmp)
{
	if (is_wall_row(tmp))
		return (WALL);
	else if (is_ceiling_floor(tmp))
		return (CEILING_FLOOR);
	else if (is_map_row(tmp))
		return (MAP);
	return (-1);
}
