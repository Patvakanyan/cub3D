/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:26:16 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 15:09:18 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.h"

int	parse_color(char *color_str)
{
	int		r;
	int		g;
	int		b;
	char	**colors;
	int		color;

	colors = ft_split(color_str, ',');
	if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
	{
		free_split(colors);
		return (ft_putstr_fd("error\n", 2), -1);
	}
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_split(colors);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_putstr_fd("error\n", 2), -1);
	color = (r << 16) | (g << 8) | b;
	return (color);
}

bool	has_extension(char *file, char *extension, char *msg)
{
	char	*tmp;

	tmp = ft_strrchr(file, '.');
	if (!tmp || ft_strcmp(tmp, extension) != 0)
	{
		ft_putstr_fd(msg, 2);
		return (false);
	}
	return (true);
}

char	*replace_space_with_zero(char **row)
{
	char	*ret;
	int		i;

	i = -1;
	ret = ft_splitdup(row);
	while (ret[++i])
		if (ret[i] == ' ')
			ret[i] = '0';
	return (ret);
}

char	**ft_splitcpy(char **str)
{
	int		i;
	char	**ret;

	i = 0;
	while (str[i])
		i++;
	ret = ft_calloc(i + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = ft_strdup(str[i]);
		i++;
	}
	return (ret);
}
