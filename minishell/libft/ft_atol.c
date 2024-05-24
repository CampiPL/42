/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:47:12 by rmakhlou          #+#    #+#             */
/*   Updated: 2022/12/15 02:13:46 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_atol(const char *nptr)
{
	ssize_t	i;
	ssize_t	a;

	i = 0;
	a = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		nptr++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		a = (a * 10) + (nptr[i++] - 48);
	if (nptr[0] == '-')
		a = -1 * a;
	return (a);
}
