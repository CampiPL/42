/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:54:53 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:54:54 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**t;

	if (!s)
		return (NULL);
	t = ft_calloc((ft_cnt_wrd(s, c) + 1), sizeof(char *));
	if (!t)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else if (*s != c && *s)
		{
			t[j] = ft_substr(s, 0, ft_strlen(s, c));
			if (!t[j])
				return (ft_freelst(t), NULL);
			s = s + ft_strlen(s, c);
			j++;
		}
	}
	return (t);
}
