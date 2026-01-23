/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:08 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/23 22:44:32 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "./init.h"
# include "./raycasting.h"
# include "./struct.h"
# include "./tools.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define W 1000
# define H 1000
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 1731
# define KEY_A 1734
# define KEY_S 1753
# define KEY_D 1751
# define TEX 64

/* ========== GAME LIFECYCLE FUNCTIONS ========== */
int		close_game(t_player *player);

/* ========== FILE/PARSING FUNCTIONS ========== */
int		validate_file_open(char *file);
int		get_type(char *tmp);
t_map	*give_list_map(int fd);

#endif
