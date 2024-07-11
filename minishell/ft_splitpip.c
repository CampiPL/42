/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitpip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:58:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/11 18:46:21 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cnt(char *s, char c)
{
	int	i;

	i = 0;
	while (s && *s)
	{
		if (*s == 34 || *s == 39)
			s += (ft_strlen(s + 1, *s) + 1);
		if (*s++ == c)
			i++;
	}
	return (i);
}

static	size_t	ft_strlensc(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
	{
		if (s[i] == 34 || s[i] == 39)
			i += (ft_strlen(s + i + 1, s[i]) + 1);
		i++;
	}
	return (i);
}

char	**ft_splitpip(char *s, char c)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_calloc(ft_cnt(s, c) + 2, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (s && *s)
	{
		tmp[i] = ft_substr(s, 0, ft_strlensc(s, c));
		tmp[i] = ft_strsimp(tmp[i]);
		s += ft_strlensc(s, c);
		if (*s == c)
			s++;
		i++;
	}
	return (tmp);
}
