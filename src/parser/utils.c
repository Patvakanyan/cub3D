/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:00:26 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/24 15:07:02 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	trim_newlines(char **src)
{
	int		len;
	char	*new;

	if (!src || !*src)
		return ;
	len = ft_strlen(*src);
	while (len > 0 && (*src)[len - 1] == '\n')
		len--;
	new = ft_substr(*src, 0, len);
	free(*src);
	*src = ft_strdup(new);
	free(new);
}

int	ft_inset(char target, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (target == src[i])
			return (1);
		++i;
	}
	return (0);
}

int	split_len(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		++i;
	return (i);
}

void	print_configs(t_config *config)
{
	int	i;

	printf("North: %s\n", config->north);
	printf("South: %s\n", config->south);
	printf("East: %s\n", config->east);
	printf("West: %s\n", config->west);
	printf("\n");
	printf("Ceiling: %x\n", config->ceiling);
	printf("Floor: %x\n", config->floor);
	printf("\n");
	printf("Map:\n");
	i = 0;
	while (config->map->map[i])
	{
		printf("%s\n", config->map->map[i]);
		++i;
	}
	printf("Map size: %d\n", config->map->height);
	printf("Max width: %d\n", config->map->max_width);
}
