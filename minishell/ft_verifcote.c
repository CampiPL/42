/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifcote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/11 18:46:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_verifcote(char *s)
{
	int		i;
	char	c;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		i += (ft_strlenstr(s + i, "\"'"));
		c = s[i];
		if (!c)
			break ;
		while (s[++i] != c)
			if (!s[i])
				return (ft_printf(2, "Error : unclosed cote\n"));
	}
	return (0);
}
