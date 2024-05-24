/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:54:36 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:54:37 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_move(char *dest, const char *src, size_t n, int a)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (a == -1)
		i = n - 1;
	while (j++ < n)
	{
		dest[i] = src[i];
		i = i + a;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (src < dest)
		ft_move ((char *)dest, (const char *)src, n, -1);
	else
		ft_move ((char *)dest, (const char *)src, n, 1);
	return (dest);
}
