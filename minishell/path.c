/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:03:12 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/14 17:03:22 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path(char *cmd, char **env)
{
	char	*s;

	while (env && *env)
	{
		if (cmd[0] == '/')
			s = ft_substr(cmd, 0, ft_strlen(cmd, 32));
		else
		{
			s = ft_strjoin(*env, "/", 1);
			s = ft_strjoin(s, ft_substr(cmd, 0, ft_strlen(cmd, 32)), 6);
		}
		if (!access(s, F_OK))
			return (free(cmd), s);
		env++;
		free(s);
	}
	return (cmd);
}
