/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_penv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 08:08:56 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/16 19:55:29 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_penv(char **env)
{
	while (env && *env)
	{
		if (!ft_strncmp("PATH=", *env, 5))
			return (ft_split((*env + 5), ':'));
		env++;
	}
	return (NULL);
}
