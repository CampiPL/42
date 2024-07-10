/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:33:04 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/10 14:43:08 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**cmd_tab(t_cmd *start)
{
	t_cmd	*cmd;
	char	**tab;
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
	if (!(tab = malloc(sizeof(char *) * i)))
		return (NULL);
	cmd = start->next;
	tab[0] = start->str;
	i = 1;
	while (cmd && cmd->type < TRUNC)
	{
		tab[i++] = cmd->str;
		cmd = cmd->next;
	}
	tab[i] = NULL;
	return (tab);
}

void	exec_cmd(t_b *mini, t_cmd *cmd)
{
	char	**cmd;
	int		i;

	cmd = cmd_tab(cmd);
	i = 0;
	while (cmd && cmd[i])
	{
		cmd[i] = expansions(cmd[i], mini->env, mini->ret);
		i++;
	}
	if (cmd && is_builtin(cmd[0]))
		mini->ret = exec_builtin(cmd, mini);
	else if (cmd)
		mini->ret = exec_bin(cmd, mini->env, mini);
	free_tab(cmd);
}
