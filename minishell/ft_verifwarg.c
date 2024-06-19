/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifwarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/15 14:38:16 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_verifwarg(char *s)
{
	size_t	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (ft_strchr("\\;", s[i]))
			return (ft_printf(2, "Invalid Input : %c\n", s[i]));
		if (ft_strchr("\"'", s[i]))
			i += ft_strlen(s + i + 1, s[i]) + 1;
	}
	return (0);
}
