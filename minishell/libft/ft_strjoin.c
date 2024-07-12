/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:05 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:55:06 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int clear)
{
	size_t	i;
	size_t	j;
	char	*t;

	i = 0;
	j = 0;
	t = ft_calloc((ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1), sizeof(char));
	if (!t)
		return (NULL);
	while (s1 && s1[j])
		t[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		t[i++] = s2[j++];
	if (clear % 2 == 0)
		free(s1);
	if (clear % 3 == 0)
		free(s2);
	return (t);
}
