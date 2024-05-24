/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:05 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/05/07 16:18:09 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *s1, void *s2, int a, int *b)
{
	int		i;
	char	*t;
	char	*t1;
	char	*t2;

	i = -1;
	t1 = (char *)s1;
	t2 = (char *)s2;
	t = malloc((*b) * sizeof(char));
	if (!t)
		return (NULL);
	while (++i < a)
		t[i] = t1[i];
	i--;
	while (++i < *b)
		t[i] = t2[i - a];
	ft_freebulk("ss", s1, s2);
	return ((void *)t);
}
