/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:28:33 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/27 02:35:51 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

t_config	*parse_configs(int fd)
{
	char		*line;
	char		*ln;
	t_config	*configs;

	configs = init_configs();
	if (!configs)
		return (ft_putstr_fd(ALLOC_ERR, 2), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n' && !ft_inset(*line, "10"))
		{
			ln = skip_spaces(line);
			if (!place_config(configs, ln))
				return (free_stuff(configs, line), NULL);
		}
		else if (ft_inset(*line, "10 ") && !parse_map(configs, &line, fd))
			return (free_stuff(configs, line), NULL);
		free(line);
		line = get_next_line(fd);
	}
	return (configs);
}
