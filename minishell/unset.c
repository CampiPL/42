/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:39:20 by macrespo          #+#    #+#             */
/*   Updated: 2024/07/13 21:20:35 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **args, t_b *mini)
{
	char		**env;
	char		**new_env;
	size_t		i;
	size_t		j;

	if (!(args[1]))
		return ;
	i = 0;
	j = 0;
	env = mini->env;
	new_env = ft_calloc(ft_lstlen(mini->env), sizeof(char *));
	while (env[j])
	{
		if (ft_strncmp(env[j], args[1], strlen(args[1]))
			== 0 && env[j][strlen(args[1])] == '=')
			j++;
		else
			new_env[i++] = ft_strdup(env[j++]);
	}
	ft_freelst(mini->env);
	mini->env = new_env;
}
