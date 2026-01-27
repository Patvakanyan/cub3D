/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:08 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/27 17:07:57 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define W 1000
# define H 1000
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_E 101
# define TEX 64
# define TARGET_FPS 60

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "./init.h"
# include "./raycasting.h"
# include "./struct.h"
# include "./tools.h"
# include "./bonus.h"
# include "./parser.h"

int	close_game(t_game *game);

#endif
