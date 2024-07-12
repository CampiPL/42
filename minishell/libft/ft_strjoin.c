/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:05 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/12 12:30:19 by jdepka           ###   ########.fr       */
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

char	*strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	result = (char *)malloc(s1_len + s2_len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	return (result);
}
