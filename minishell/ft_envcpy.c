/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:57:24 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/13 20:22:04 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**envcpy(char **env)
{
	size_t	i;
	char	**rt;

	i = 0;
	rt = ft_calloc(ft_lstlen(env) + 1, sizeof(char *));
	if (!rt)
		return (NULL);
	while (*env)
		rt[i++] = ft_strdup(*env++);
	return (rt);
}
