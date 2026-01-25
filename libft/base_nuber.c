/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_nuber.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:15:31 by alen              #+#    #+#             */
/*   Updated: 2026/01/25 18:59:03 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	base_number(char *base, unsigned long num)
{
	int	count;

	count = 0;
	if (num >= (size_t)ft_strlen(base))
		count += base_number(base, num / ft_strlen(base));
	ft_putchar(base[num % ft_strlen(base)]);
	count++;
	return (count);
}
