/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:49:25 by rbarkhud          #+#    #+#             */
/*   Updated: 2026/01/26 02:54:19 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H

# define BONUS_H

# include "./cub.h"
# include "./parser.h"

# define MINI_SIZE 5
# define PLAYER_SIZE 3

/*-----mouse hook handler-----*/
int		mouse_move(int x, int y, t_game *game);

/*-----minimap rendering-----*/
void	render_minimap(t_game *game);

/*-----doors init-----*/
int		add_door(t_door **head, int x, int y);
void	interact_door(t_game *game);
int		parse_doors_line(t_door **doors, const char *row, int y);

/*-----dealloc funtions-----*/
void	free_doors(t_door *head);


#endif