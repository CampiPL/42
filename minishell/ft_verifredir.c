/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifredir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:12:42 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/14 16:34:23 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_boolredir(char *s)
{
	int	b;

	b = 0;
	if (*s && *s == '>' && s[1] == '<')
		b = 1;
	if (*s && *s == '>' && s[1] == '|')
		b = 1;
	if (*s && *s == '>' && s[1] == ';')
		b = 1;
	if (*s && *s == '>' && s[1] == 0)
		b = 1;
	if (*s && *s == '>' && s[1] == '\n')
		b = 1;
	if (b == 1)
		return (ft_printf(2, "parse error near `%c'\n", s[1]),  b);
	return (b);
}

int	ft_verifredir(char *s)
{
	printf("t");
	if (!ft_strchr(s, '<') && !ft_strchr(s, '>'))
		return (0);
	while (s && *s)
	{
		if (*s == 34 || *s == 39)
			s += (ft_strlen(s + 1, *s) + 1);
		if (ft_boolredir(s++))
			return (1);
	}
	return (0);
}
