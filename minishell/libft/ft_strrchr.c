/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:24 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:55:25 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s, 0);
	while (i > -1)
		if (s[i--] == c)
			return ((char *)s + i + 1);
	return (NULL);
}
