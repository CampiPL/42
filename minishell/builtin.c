/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:57:37 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/13 15:27:21 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *command)
{
	if (strcmp(command, "echo") == 0)
		return (1);
	if (strcmp(command, "cd") == 0)
		return (1);
	if (strcmp(command, "pwd") == 0)
		return (1);
	if (strcmp(command, "env") == 0)
		return (1);
	if (strcmp(command, "export") == 0)
		return (1);
	if (strcmp(command, "unset") == 0)
		return (1);
	return (0);
}

void	exec_builtin(char **args, t_b *mini)
{
	(void) mini;
	if (strcmp(args[0], "echo") == 0)
		ft_echo(args);
	if (strcmp(args[0], "cd") == 0)
		ft_cd(args, mini->env);
	if (strcmp(args[0], "pwd") == 0)
		ft_pwd();
	if (strcmp(args[0], "env") == 0)
		ft_env(mini->env);
	if (strcmp(args[0], "export") == 0)
		ft_export(args, mini->env, mini->penv);
	/*
	if (strcmp(args[0], "unset") == 0)
		ft_unset(args, mini);
	*/
}
