/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:22:50 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/18 19:16:12 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	validate_file_open(char *file)
{
	int	fd;

	if (has_extension(file, ".cub", "file dont have .cub extension\n") == false)
	{
		ft_putstr_fd("file dont have .cub extension\n", 2);
		return (-1);
	}
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
	char	**tmp;

	tmp = ft_split(row, ' ');
	if (!ft_strcmp(tmp[0], "NO") || !ft_strcmp(tmp[0], "SO")
		|| !ft_strcmp(tmp[0], "WE") || !ft_strcmp(tmp[0], "EA"))
	{
		free_split(tmp);
		return (1);
	}
	free_split(tmp);
	return (0);
}
