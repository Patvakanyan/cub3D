/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:28:54 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 01:39:50 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# define ARGC_ERROR "Error: Invalid number of arguments.\n"
# define FD_ERROR "Error: unable to open the file.\n"
# define COLOR_ERR_1 "Error: wrong count for color argument.\n"
# define COLOR_ERR_2 "Error: wrong color number found.\n"
# define HINT "Hint: use a number in range [0, 255] for each (r, g, b).\n"
# define DUP_ERROR "Error: duplicate of config `"
# define WRONG_CONFIG "Error: unexpected config found `"
# define EXTENSION_ERR "Error: given file doesn't have extension "
# define CUB_EXTENSION_ERR "Error: given file doesn't have extension *.cub.\n"
# define WRONG_ORDER_ERR "Error: configs misorder in *.cub file.\n"
# define ALLOC_ERR "Error: bad alloc.\n"
# define PLAYER_404 "Error: player not found.\n"
# define GRDON_MAP "Error: map contains disconnected parts.\n"
# define MAP_CLOSE_ERROR "Error: map walls arent closed.\n"
# define NORTH_FD_ERR "Error: north texture destination unreachable.\n"
# define SOUTH_FD_ERR "Error: south texture destination unreachable.\n"
# define EAST_FD_ERR "Error: east texture destination unreachable.\n"
# define WEST_FD_ERR "Error: west texture destination unreachable.\n"

# include "../libft/libft.h"
# include "./struct.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_game	t_game;
typedef struct s_player	t_player;

typedef struct s_map_list
{
	char				*row;
	struct s_map_list	*next;
}	t_map_list;

typedef struct s_map
{
	char	**map;
	int		max_width;
	int		height;
}	t_map;

typedef struct s_config
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		ceiling;
	int		floor;
	t_map	*map;
}	t_config;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

/*-----parser-----*/
t_config	*parse_configs(int fd);
int			parse_map(t_config *config, char **first_line, int fd);
t_map		*list_to_map(t_map_list *list, int size);

/*-----parser helpers-----*/
int			split_len(char **split);
void		replace_map_spaces(t_map *map);
int			safe_place(t_config *config, char **src, char config_name);
int			assign_color(t_config *config, char *src, char c_f);
int			place_config(t_config *configs, char **spl);

/*-----init-----*/
void		init_player_dir(t_player *p, char c);
t_config	*init_configs(void);
t_map		*init_map(int height);
t_map_list	*new_node(char **val);

/*-----checkers-----*/
int			textures_are_complete(t_config *c);
int			textures_not_set(t_config *c);
int			colors_not_set(t_config *c);
int			colors_are_complete(t_config *c);
int			check_first_arg(char *arg);
int			check_file_extension(char **src, char *target);
int			check_file_destination(t_config *config);
int			check_map_empty_lines(t_map_list *head);

/*-----deallocation-----*/
void		free_split(char **split);
void		free_map(t_map *map, int size);
void		free_map_lst(t_map_list *head);
void		free_configs(t_config *configs);
void		free_grdon_map(t_map_list *head, t_map *map, int ind);
void		free_stuff(t_config *config, char *line, char **split);

/*-----validation-----*/
int			validate_map(t_game *game);
int			validate_configs(t_game *game);

/*-----validation helpers-----*/
t_map		*copy_map(t_map *src_map);
int			find_player_pos(t_game *game, t_map *map);

/*-----vaidation checkers-----*/
int			is_player(char c);
int			is_valid_char(char c);
int			check_player_pos(t_map *map, int x, int y);

/*-----utils-----*/
void		trim_newlines(char **src);
int			ft_inset(char target, char *src);
void		print_configs(t_config *config);

#endif