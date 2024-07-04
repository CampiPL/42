/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifredir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:12:42 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/27 15:09:45 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_skipredir(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == '>' || s[i] == '<')
		i++;
	return (i);
}

static int	ft_boolredir(char *s)
{
	int	i;
	char	*err;

	i = 0;
	err = ft_strdup("syntax error near unexpected token");
	if (*s && ft_skipredir(s) > 2)
		i = ft_printf(2, "%s `%c%c'\n", err, *s, s[1]);
	else if (*s && *s == '>' && s[1] == '<')
		i = ft_printf(2, "%s `%c'\n", err, s[1]);
	else if (*s && *s == '>' && ft_strlen(s + 1, 0) == ft_skipchar(s + 1, 32))
		i = ft_printf(2, "%s `%s'\n", err, "\\n");
	else if (*s && *s == '>' && ft_strlen(s + 1, '|') == ft_skipchar(s + 1, 32))
		i = ft_printf(2, "%s `%c'\n", err, '|');
	else if (*s && *s == '>' && s[1] == '\n')
		i = ft_printf(2, "%s `%c'\n", err, s[1]);
	return (free(err), i);
}

int	ft_verifredir(char *s)
{
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
