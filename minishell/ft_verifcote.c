/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifcote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2023/01/15 14:57:26 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
/*
static char	*ft_askmore(char *s, char c)
{
	char	*tmp;

	tmp = NULL;
	while (!ft_strchr(tmp, c))
	{
		free(tmp);
		tmp = readline("> ");
		s = ft_strjoin(s, "\n", 2);
		s = ft_strjoin(s, tmp, 2);
	}
	free(tmp);
	return (s);
}
*/
static	int	ft_vcote(char *s, int *i, int *a, char c)
{
		if (s[*i] == c)
		{
			*i += 1;
			while (s[*i] != c)
			{
				if (!s[*i])
				{
					if (c == 34)
						*a = 1;
					if (c == 39)
						*a = 2;
					return (1);
				}
				*i += 1;
			}
		}
		return (0);
}

//char	*ft_verifcote(char *s)
int	ft_verifcote(char *s)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (ft_vcote(s, &i, &a, 34))
			break;
		if (ft_vcote(s, &i, &a, 39))
			break;
		else if (s[i])
			i++;
	}
	if (a == 1 || a == 2)
		return (1);
//		s = ft_askmore(s, 34);
//	if (a == 2)
//		s = ft_askmore(s, 39);
//	return (s);
	return (0);
}
