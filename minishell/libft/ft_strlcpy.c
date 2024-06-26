/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:10 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/11 19:46:37 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (size == 0)
		return (ft_strlen(src, 0));
	if (size > ft_strlen(src, 0))
		size = ft_strlen(src, 0) + 1;
	ft_memcpy(dst, src, size - 1);
	dst[size] = 0;
	return (ft_strlen(src, 0));
}
