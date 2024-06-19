/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:13 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/08 16:10:38 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenstr(const char *s, char *c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && !ft_strchr(c, s[i]))
		i++;
	return (i);
}
