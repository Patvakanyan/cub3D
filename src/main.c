/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:49:32 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/14 19:14:11 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	free_data(t_data *data)
{
	if (data->map)
		free_split(data->map);
	if (data->celling_floor)
		free_split(data->celling_floor);
	if (data->wall)
		free_split(data->wall);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	if (argc > 2)
		return (1);
	pars_map(argv[1], data);
	while (data->map && data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	printf("\n");
	while (data->celling_floor && data->celling_floor[j])
	{
		printf("%s\n", data->celling_floor[j]);
		j++;
	}
	printf("\n");
	while (data->wall && data->wall[k])
	{
		printf("%s\n", data->wall[k]);
		k++;
	}
	free_data(data);
	return (0);
}
