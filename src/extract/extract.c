/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:10:17 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/18 19:19:11 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

char	**extract_ceiling_floor(t_map **map)
{
	char	**ret;
	int		counter;

	counter = -1;
	if ((*map)->type != CEILING_FLOOR)
		return (NULL);
	ret = ft_calloc(3, sizeof(char *));
	if (!ret)
		return (NULL);
	while ((*map) && (*map)->type == CEILING_FLOOR)
	{
		if (check_single_parameter((*map), (*map)->row[0], CEILING_FLOOR))
			return (free(ret), NULL);
		ret[++counter] = ft_splitdup((*map)->row);
		(*map) = (*map)->next;
	}
	if (counter < 1)
		return (free_split(ret), NULL);
	return (ret);
}

char	**extract_wall(t_map **map)
{
	char	**ret;
	int		counter;

	counter = 0;
	if ((*map)->type != WALL)
		return (NULL);
	ret = ft_calloc(5, sizeof(char *));
	if (!ret)
		return (NULL);
	ret[4] = NULL;
	while ((*map) && (*map)->type == WALL)
	{
		if (!has_extension((*map)->row[1], ".ber",
				"file dont have .ber extension\n")
			|| check_single_parameter((*map), (*map)->row[0], WALL))
			return (free_split(ret), NULL);
		ret[counter] = ft_splitdup((*map)->row);
		counter++;
		(*map) = (*map)->next;
	}
	if (counter < 4)
		return (free_split(ret), ft_putstr_fd("error", 2), NULL);
	return (ret);
}

bool	extract(t_map *head, t_data *data)
{
	if (head->type == CEILING_FLOOR)
	{
		data->celling_floor = extract_ceiling_floor(&head);
		if (!data->celling_floor)
			return (false);
		data->wall = extract_wall(&head);
		if (!data->wall)
			return (false);
		data->map = extract_map(&head);
		if (!data->map)
			return (false);
	}
	else
	{
		data->wall = extract_wall(&head);
		if (!data->wall)
			return (false);
		data->celling_floor = extract_ceiling_floor(&head);
		if (!data->celling_floor)
			return (false);
		data->map = extract_map(&head);
		if (!data->map)
			return (false);
	}
	return (true);
}

char	**extract_map(t_map **map)
{
	char	**ret;
	int		counter;

	if ((*map)->type != MAP)
		return (NULL);
	counter = get_map_size((*map));
	if (counter == 0)
		return (ft_putstr_fd("error\n", 2), NULL);
	ret = ft_calloc(counter + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	counter = 0;
	while ((*map) && (*map)->type == MAP)
	{
		if (check_map_line((*map)->row) == false)
			return (free_split(ret), ft_putstr_fd("error\n", 2), NULL);
		ret[counter] = replace_space_with_zero((*map)->row);
		counter++;
		(*map) = (*map)->next;
	}
	return (ret);
}

bool	pars_map(char *file, t_data *data)
{
	t_map	*tmp;
	t_map	*map;
	int		fd;

	fd = validate_file_open(file);
	if (fd == -1)
		return (NULL);
	map = give_list_map(fd);
	if (!map)
		return (free_list(map), close(fd), false);
	tmp = map;
	if (tmp->type == MAP || extract(tmp, data) == false)
		return (free_list(map), close(fd), false);
	free_list(map);
	close(fd);
	return (true);
}
