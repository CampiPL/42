/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 05:13:18 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/05/07 16:00:08 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(size_t n, size_t b)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		n = n / b;
		i++;
	}
	return (i);
}

char	*ft_ultoa_b(unsigned long int n, char *base)
{
	size_t	i;
	char	*s;
	int		b;

	b = ft_strlen(base, 0);
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_size(n, b);
	s = malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[i--] = 0;
	while (n > 0)
	{
		s[i--] = base[n % b];
		n = n / b;
	}
	return (s);
}
