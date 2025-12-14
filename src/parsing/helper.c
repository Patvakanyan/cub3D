/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:22:50 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/13 17:37:10 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	validate_file_open(char *file)
{
	int		fd;
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (!extension || ft_strcmp(extension, ".cub") != 0)
		return (-1);
	fd = open(file, O_RDONLY);
	return (fd);
}

int	chek_row(char *tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] != ' ')
			return (0);
	}
	return (1);
}

void	free_split(char **tmp)
{
	int	i;

	i = 0;
	if (!tmp)
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i] = NULL;
		++i;
	}
	free(tmp);
	tmp = NULL;
}

int	is_wall_row(char *row)
{

	if (!ft_strcmp(row, "NO") || !ft_strcmp(row, "SO")
		|| !ft_strcmp(row, "WE") || !ft_strcmp(row, "EA"))
		return (1);
	return (0);
}
