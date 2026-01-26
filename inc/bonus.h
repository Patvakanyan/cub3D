/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:49:25 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 15:48:48 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H

# define BONUS_H

# include "./cub.h"

# define MINI_SIZE 5
# define PLAYER_SIZE 3

typedef struct s_game	t_game;
typedef struct s_door	t_door;
typedef struct s_config	t_config;

/*-----mouse hook handler-----*/
int		mouse_move(int x, int y, t_game *game);

/*-----minimap rendering-----*/
void	render_minimap(t_game *game);

/*-----doors init-----*/
int		add_door(t_door **head, int x, int y);
void	interact_door(t_game *game);
int		can_move(t_game *game, double new_x, double new_y);
int		parse_doors_line(t_config *config, const char *row, int y);

/*-----dealloc funtions-----*/
void	free_doors(t_door *head);

#endif