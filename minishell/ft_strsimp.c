/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsimp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/12 12:11:01 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_cpycote(char *rt, char *s, size_t *i, size_t *j)
{
	size_t	a;
	size_t	b;

	a = *i;
	b = *j;
	rt[a++] = s[b++];
	while (s[b] && s[b] != s[*j])
		rt[a++] = s[b++];
	rt[a++] = s[b++];
	*i = a;
	*j = b;
}

char	*ft_strsimp(char *s)
{
	size_t		i;
	size_t		j;
	char		*rt;

	i = 0;
	rt = ft_calloc(ft_strlen(s, 0) + 1, sizeof(char));
	if (!rt)
		return (printf("Not enough memory, malloc failed"), NULL);
	j = ft_skipchar(s, 32);
	while (s[j])
	{
		if (ft_isspace(s[j]))
		{
			rt[i++] = s[j++];
			j += ft_skipchar(s + j, 32);
		}
		else if (s[j] == 34 || s[j] == 39)
			ft_cpycote(rt, s, &i, &j);
		else
			rt[i++] = s[j++];
	}
	return (free(s), rt);
}
