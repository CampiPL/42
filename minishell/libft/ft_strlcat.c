/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:07 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:55:08 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src, 0));
	while (dst[i] && i < size)
		i++;
	if (i == size)
		return (i + ft_strlen(src, 0));
	while (*src && i < size - 1)
		dst[i++] = *src++;
	dst[i] = 0;
	return (i + ft_strlen(src, 0));
}
