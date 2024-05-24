/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:54:59 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:55:00 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*dst;

	dst = malloc((ft_strlen(s, 0) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s, ft_strlen(s, 0));
	dst[ft_strlen(s, 0)] = 0;
	return (dst);
}
