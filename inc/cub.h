/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:08 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/16 21:11:04 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "./init.h"
# include "./struct.h"
# include "./tools.h"
# include "./raycasting.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include "mlx.h"

# define W 1000
# define H 1000
# define KEY_ESC 65307
# define KEY_W 1731
# define KEY_A 1734
# define KEY_S 1753
# define KEY_D 1751
# define TEX 64



int					test_hook(int keycode, void *game);
int					close_game(t_player *player);
int					validate_file_open(char *file);
int					chek_row(char *tmp);
int					get_type(char *tmp);
void				free_list(t_map *list);
t_map				*give_list_map(int fd);
void				free_split(char **tmp);
void				free_split_all(char ***split);
void				free_data(t_data *data);
void				free_game(t_game *game);
int					is_wall_row(char *row);

char				**extract_map(t_map **map);
bool				check_first_last_row(char *row);
int					get_size_of_split(char **split);
bool				pars_map(char *file, t_game *game);
void				start_game_loop(t_game *game);

void				put_pixel(t_img *img, int x, int y, int color);
#endif
