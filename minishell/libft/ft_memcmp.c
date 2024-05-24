/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:54:31 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:54:32 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = -1;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (++i < n)
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
	return (0);
}
