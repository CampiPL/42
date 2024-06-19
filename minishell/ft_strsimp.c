/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsimp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/11 15:25:42 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count(char *s)
{
	int	rt;

	rt = 0;
	s += ft_skipchar(s, 32);
	while (s && *s)
	{
		if (*s && ft_isspace(*s))
		{
			rt++;
			s += ft_skipchar(s, 32);
		}
		else if (*s && (*s == 34 || *s == 39))
		{
			rt += (ft_strlen(s + 1, *s) + 1);
			s += (ft_strlen(s + 1, *s) + 1);
		}
		else
		{
			s++;
			rt++;
		}
	}
	return (rt);
}
/*
void	ft_copycote(char **s, char *rt, int &i)
{
	
}
*/
char	*ft_strsimp(char *s)
{
	size_t		i;
	char	*rt;
	char	c;

	if (!s)
		return (NULL);
	i = 0;
	rt = ft_calloc(ft_count(s) + 1, sizeof(char));
	if (!rt)
		return (printf("Not enough memory, malloc failed"), "");
	s += ft_skipchar(s, 32);
	while (s && *s)
	{
		if (*s && ft_isspace(*s))
		{
			rt[i++] = *s++;
			s += ft_skipchar(s, 32);
		}
		else if (*s && (*s == 34 || *s == 39))
		{
			c = *s;
			rt[i++] = *s++;
			while (*s && *s != c)
				rt[i++] = *s++;
			rt[i++] = *s++;
		}
		else
			rt[i++] = *s++;
	}
	if (ft_strlen(rt, 0) > 1 && rt[i - 1] == 32)
		rt[i - 1] = 0;
	return (rt);
}
