/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:26:16 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/18 19:14:02 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

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
