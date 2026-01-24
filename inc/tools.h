/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:11:28 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/24 15:37:16 by rbarkhud         ###   ########.fr       */
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

int		test_hook(int keycode, void *ptr);
void	free_game(t_game *game);

#endif