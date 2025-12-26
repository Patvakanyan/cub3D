/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:08 by apatvaka          #+#    #+#             */
/*   Updated: 2025/12/26 15:43:07 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include "mlx.h"
typedef enum s_type
{
	WALL,
	CEILING_FLOOR,
	MAP
}					t_type;

typedef struct s_map
{
	char			**row;
	t_type			type;
	struct s_map	*next;
}					t_map;

typedef struct s_data
{
	char			**map;
	char			**celling_floor;
	char			**wall;
}					t_data;

int					validate_file_open(char *file);
int					chek_row(char *tmp);
int					get_type(char *tmp);
void				free_list(t_map *list);
t_map				*give_list_map(int fd);
void				free_split(char **tmp);
int					is_wall_row(char *row);
char				*ft_splitdup(char **str);

bool				check_single_parameter(t_map *tmp, char *param,
						t_type type);
bool				pars_map(char *file, t_data *data);
char				**extract_map(t_map **map);
int					get_map_size(t_map *map);
bool				has_extension(char *file, char *extension, char *msg);
bool				check_map_line(char **line);
bool				check_first_last_row(char *row);
int					get_size_of_split(char **split);

char				*replace_space_with_zero(char **row);
#endif
