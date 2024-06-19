/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:54:25 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/08 12:23:42 by rmakhlou         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	int		i;
	char	*s;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
		s[i] = '-';
	return (s);
}
