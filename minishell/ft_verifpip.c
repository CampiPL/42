/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifpip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:58:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/19 11:38:17 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_verifpip(char *s)
{
	if (!ft_strchr(s, '|'))
		return (0);
	while (s && *s)
	{
		if (*s == 34 || *s == 39)
			s += (ft_strlen(s + 1, *s) + 1);
		if (*s++ == '|')
			if (ft_strlen(s, 0) == ft_skipchar(s, 32))
				return (ft_printf(2,
						"syntax error near unexpected token `|'\n"));
	}
	return (0);
}
