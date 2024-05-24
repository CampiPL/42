/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:30 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:55:31 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s, 0) - start)
		len = ft_strlen(s, 0) - start;
	if (start >= ft_strlen(s, 0))
		return (ft_strdup(""));
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	while (i < len && s[start])
		dst[i++] = s[start++];
	return (dst);
}
