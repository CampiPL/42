/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 05:13:18 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/05/07 16:17:54 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_ltoa(long int n)
{
	int		i;
	char	*s;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_size(n);
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	s = ft_calloc(i-- + 1, sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		s[i--] = n % 10 + 48;
		n = n / 10;
	}
	if (n == 0 && i == 0)
		s[i++] = '-';
	return (s);
}
