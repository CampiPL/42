/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsimp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2023/02/14 09:03:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static void	ft_cntcote(char *s, int *i, int *rt, char c)
{
		if (s[*i] == c)
		{
			*i += 1;
			*rt += 1;
			while (s[*i] && s[*i] != c)
			{
				*i += 1;
				*rt += 1;
			}
		}
}

static int	ft_count(char *s)
{
	int	i;
	int	rt;

	i = 0;
	rt = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] < 33)
			i++;
		ft_cntcote(s, &i, &rt, 34);
		ft_cntcote(s, &i, &rt, 39);
		if (s[i] && s[i] > 32)
		{
			i++;
			rt++;
		}
		if (s[i] && s[i] < 33 && s[i - 1] > 32)
			rt++;
	}
	return (rt);
}

static void	ft_cotecpy(char *s, char *rt, int *i, int *j)
{
		if (s[*i] == 34)
		{
			rt[*j] = s[*i];
			*i += 1;
			*j += 1;
			while (s[*i] && s[*i] != 34)
			{
				rt[*j] = s[*i];
				*i += 1;
				*j += 1;
			}
		}
		if (s[*i] == 39)
		{
			rt[*j] = s[*i];
			*i += 1;
			*j += 1;
			while (s[*i] && s[*i] != 39)
			{
				rt[*j] = s[*i];
				*i += 1;
				*j += 1;
			}
		}
}

char	*ft_strsimp(char *s)
{
	int	i;
	int	j;
	char	*rt;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	rt = ft_calloc(ft_count(s) + 1, sizeof(char));
	if (!rt)
		return (printf("Not enough memory, malloc failed"), "");
	while (s[i])
	{
		while (s[i] && s[i] < 33)
			i++;
		ft_cotecpy(s, rt, &i, &j);
		if (s[i] && s[i] > 32)
			rt[j++] = s[i++];
		if (s[i] && s[i] < 33 && s[i - 1] > 32)
			rt[j++] = 32;
	}
	if (ft_strlen(rt, 0) > 1 && rt[j - 1] == 32)
		rt[j - 1] = 0;
	free(s);
	return(rt);
}
