/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:13 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/12 12:29:51 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	strlen(const char *s)
{
	size_t	dlugosc;

	dlugosc = 0;
	while (s[dlugosc] != '\0')
	{
		dlugosc++;
	}
	return (dlugosc);
}
