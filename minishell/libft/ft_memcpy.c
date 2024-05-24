/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:54:34 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:54:35 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*u;

	i = -1;
	if (!dest && !src)
		return (NULL);
	t = (unsigned char *)src;
	u = (unsigned char *)dest;
	while (++i < n)
		u[i] = t[i];
	return (dest);
}
