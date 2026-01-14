/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:49:32 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/14 23:24:12 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	free_split_all(char ***split)
{
	int	i;

	i = -1;
	if (!split)
		return ;
	while (split[++i])
		free_split(split[i]);
	free(split);
	split = NULL;
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_split(data->map);
	if (data->wall)
		free_split_all(data->wall);
	free(data);
	data = NULL;
}

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	get_player_dir(t_game *game, int i, int j)
{
	char	c;

	c = game->data->map[i][j];
	if (c == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
}

bool	get_player_pos(t_game *game, double *x, double *y)
{
	int	i;
	int	j;

	i = 0;
	while (game->data->map[i])
	{
		j = 0;
		while (game->data->map[i][j])
		{
			if (is_player_char(game->data->map[i][j]))
			{
				get_player_dir(game, i, j);
				game->data->map[i][j] = '0';
				*x = (double)j;
				*y = (double)i;
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	init_player(t_game *game)
{
	if (get_player_pos(game, &game->player.x, &game->player.y) == false)
		return (false);
	return (true);
}

static bool	init_img(t_game *game)
{
	game->texture[0].img = mlx_xpm_file_to_image(game->mlx,
			game->data->wall[0][1], &game->texture[0].width,
			&game->texture[0].height);
	if (!game->texture[0].img)
		return (false);
	game->texture[0].addr = mlx_get_data_addr(game->texture[0].img,
			&game->texture[0].bpp, &game->texture[0].line_len,
			&game->texture[0].endian);
	game->texture[1].img = mlx_xpm_file_to_image(game->mlx,
			game->data->wall[1][1], &game->texture[1].width,
			&game->texture[1].height);
	if (!game->texture[1].img)
		return (false);
	game->texture[1].addr = mlx_get_data_addr(game->texture[1].img,
			&game->texture[1].bpp, &game->texture[1].line_len,
			&game->texture[1].endian);
	game->texture[2].img = mlx_xpm_file_to_image(game->mlx,
			game->data->wall[2][1], &game->texture[2].width,
			&game->texture[2].height);
	if (!game->texture[2].img)
		return (false);
	game->texture[2].addr = mlx_get_data_addr(game->texture[2].img,
			&game->texture[2].bpp, &game->texture[2].line_len,
			&game->texture[2].endian);
	game->texture[3].img = mlx_xpm_file_to_image(game->mlx,
			game->data->wall[3][1], &game->texture[3].width,
			&game->texture[3].height);
	if (!game->texture[3].img)
		return (false);
	game->texture[3].addr = mlx_get_data_addr(game->texture[3].img,
			&game->texture[3].bpp, &game->texture[3].line_len,
			&game->texture[3].endian);
	return (true);
}

bool	init_game(t_game *game)
{
	if (init_player(game) == false)
		return (false);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	game->win = mlx_new_window(game->mlx, W, H, "Cub3D");
	if (!game->win)
		return (free(game->mlx), false);
	game->img.img = mlx_new_image(game->mlx, W, H);
	if (!game->img.img)
		return (free(game->win), free(game->mlx), false);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	if (init_img(game) == false)
		return (false);
	return (true);
}

void	set_game_defaults(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->data = NULL;
	game->is_game_running = true;
	game->player.x = 0.0;
	game->player.y = 0.0;
	game->player.dir_x = 1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
}

void	start_game_loop(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, test_hook, game);
	mlx_loop_hook(game->mlx, render, game);
	// mlx_hook(game->win, 17, 0L, handle_close, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	set_game_defaults(&game);
	game.data = ft_calloc(1, sizeof(t_data));
	if (!game.data)
		return (1);
	if (argc != 2)
		return (printf("Error: Invalid number of arguments\n"), free(game.data),
			1);
	if (pars_map(argv[1], &game) == false)
		return (free_data(game.data), 1);
	if (init_game(&game) == 0)
		return (free_data(game.data), 1);
	start_game_loop(&game);
	free_game(&game);
	return (0);
}
