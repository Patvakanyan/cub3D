/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:49:32 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 15:13:05 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		return (ft_putstr_fd(ARGC_ERROR, 2), 1);
	if (!check_file_extension(&argv[1], ".cub"))
		return (ft_putstr_fd(CUB_EXTENSION_ERR, 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd >= 0)
	{
		set_game_defaults(&game, fd);
		game.config = parse_configs(fd);
		if (!game.config)
			return (close(fd), ft_putstr_fd(ALLOC_ERR, 2), 1);
		if (!validate_configs(&game))
			return (close(fd), free_configs(game.config), 1);
		if (!init_game(&game))
			return (close(fd), free_game(&game), 1);
		start_game_loop(&game);
	}
	return (ft_putstr_fd(FD_ERROR, 2), 1);
}
