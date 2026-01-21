/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:49:32 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/21 12:09:31 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	main(int argc, char **argv)
{
	t_game	game;

	set_game_defaults(&game);
	game.data = ft_calloc(1, sizeof(t_data));
	if (!game.data)
		return (1);
	if (argc != 2)
		return (ft_putstr_fd("Error: Invalid number of arguments\n", 2),
			free(game.data), 1);
	if (pars_map(argv[1], &game) == false)
		return (free_data(game.data), 1);
	if (init_game(&game) == 0)
		return (free_game(&game), 1);
	start_game_loop(&game);
	free_game(&game);
	return (0);
}
