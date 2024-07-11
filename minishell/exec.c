/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:33:04 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/11 18:19:44 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**cmd_tab(t_cmd *start)
{
	t_cmd	*cmd;
	char	**cmdarg;
	int		i;

	if (!start)
		return (NULL);
	cmd = start->next;
	i = 2;
	while (cmd && cmd->type < TRUNC)
	{
		cmd = cmd->next;
		i++;
	}
	cmdarg = malloc(sizeof(char *) * i);
	if (!cmdarg)
		return (NULL);
	cmd = start;
	i = 0;
	while (cmd && cmd->type < TRUNC)
	{
		cmdarg[i++] = cmd->str;
		cmd = cmd->next;
	}
	cmdarg[i] = NULL;
	return (cmdarg);
}

void	exec_cmd(t_b *mini, t_cmd *cmd)
{
	char	**cmdarg;
	int		i;

	(void) mini;
	cmdarg = cmd_tab(cmd);
	i = 0;
	while (cmdarg[i])
		printf("%s\n", cmdarg[i++]);
	/*
	if (cmdarg && is_builtin(cmdarg[0]))
		exec_builtin(cmdarg, mini);
	*/
	if (cmdarg)
		exec_bin(cmdarg, mini);
	free_cmdarg(cmdarg);
}
