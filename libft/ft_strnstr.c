/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarkhud <rbarkhud@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:50:44 by apatvaka          #+#    #+#             */
/*   Updated: 2026/01/25 18:58:48 by rbarkhud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ft_haystack;

	i = 0;
	ft_haystack = (char *)haystack;
	if (!(*needle))
		return (ft_haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && i + j < len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			++j;
		}
		if (j == (size_t)ft_strlen(needle))
			return (&ft_haystack[i]);
		++i;
	}
	return (NULL);
}
