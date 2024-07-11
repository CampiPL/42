/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:22:43 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/11 19:00:10 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_conv2(char **rt, char *s, size_t *i)
{
	char	*var;

	if (ft_isalpha(s[*i + 1]))
	{
		*i += 1;
		var = ft_substr(s, *i, ft_strlenstr(s + *i, " '<>|\"$"));
		*rt = ft_strjoin(*rt, getenv(var));
		*i += ft_strlenstr(s + *i, " '<>|\"$");
		free(var);
	}
	else if (s[*i + 1] == 39 || s[*i + 1] == 34)
		*i += 1;
	else
	{
		*rt = ft_strjoin(*rt, ft_substr(s, *i, 1));
		*i += 1;
	}
}

char	*ft_convarg(char *s)
{
	char	*rt;
	size_t	i;

	i = 0;
	rt = NULL;
	while (s && s[i])
	{
		if (s[i] == 39)
		{
			rt = ft_strjoin(rt, ft_substr(s, i++, 1));
			rt = ft_strjoin(rt, ft_substr(s, i,
						ft_strlen(s + i, 39) + 1));
			i += ft_strlen(s + i, 39) + 1;
		}
		else if (s[i] == '$')
			ft_conv2(&rt, s, &i);
		else
		{
			rt = ft_strjoin(rt, ft_substr(s, i,
						ft_strlenstr(s + i, "'$")));
			i += ft_strlenstr(s + i, "'$");
		}
	}
	return (free(s), rt);
}
