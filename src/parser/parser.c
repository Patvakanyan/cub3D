/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:28:33 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 15:06:49 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"


t_config	*parse_configs(int fd)
{
	char		*line;
	char		**spl;
	t_config	*configs;

	configs = init_configs();
	line = get_next_line(fd);
	while (line)
	{
		if (ft_inset(*line, "10 ") && !parse_map(configs, &line, fd))
			return (free_stuff(configs, line, NULL), NULL);
		else if (*line != '\n' && !ft_inset(*line, "10 "))
		{
			spl = ft_split(line, ' ');
			if (!spl)
				return (free_stuff(configs, line, NULL), NULL);
			if (!check_first_arg(spl[0]) || !place_config(configs, spl))
				return (free_stuff(configs, line, spl), NULL);
			free_split(spl);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (configs);
}
