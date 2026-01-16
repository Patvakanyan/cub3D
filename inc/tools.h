/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:11:28 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/16 21:12:09 by apatvaka         ###   ########.fr       */
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

bool	get_player_pos(t_game *game, double *x, double *y);

int		test_hook(int keycode, void *ptr);

void	free_data(t_data *data);
void	free_list(t_map *list);
void	free_game(t_game *game);

#endif
