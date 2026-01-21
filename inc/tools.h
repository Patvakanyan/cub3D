/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:11:28 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/21 12:33:01 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "../inc/cub.h"
# include "../libft/libft.h"
# include "./struct.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

bool	pars_map(char *file, t_game *game);
int		parse_color(char *color_str);
bool	has_extension(char *file, char *extension, char *msg);
char	*replace_space_with_zero(char **row);
char	**ft_splitcpy(char **str);
bool	check_single_parameter(t_map *tmp, char *param, t_type type);
char	*ft_splitdup(char **str);
int		get_map_size(t_map *map);
bool	check_map_line(char **line);
char	**extract_map(t_map **map);
int		is_wall_row(char *row);
int		chek_row(char *tmp);
int		key_push(int keycode, void *ptr);
void	move_player(t_game *game, char direction);
void	move_character(t_game *game, int direction);

int		validate_file_open(char *file);
bool	get_player_pos(t_game *game, double *x, double *y);

/* Raycasting helper functions */
void	put_pixel(t_img *img, int x, int y, int color);
void	step_and_side(t_game *g, t_ray *r);
void	dda(t_game *g, t_ray *r);
int		get_tex_color(t_img *tex, int tex_x, int tex_y);

void	free_split(char **tmp);
void	free_split_all(char ***split);
void	free_data(t_data *data);
void	free_list(t_map *list);
void	free_game(t_game *game);

#endif
