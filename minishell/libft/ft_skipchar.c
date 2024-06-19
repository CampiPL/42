/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:13 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/09 20:01:38 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_skipchar(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] == c)
		i++;
	return (i);
}
