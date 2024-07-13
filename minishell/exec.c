/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:33:04 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/13 21:16:57 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_tab(t_cmd *start)
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

	if (mini->exec == 0)
		return ;
	cmdarg = cmd_tab(cmd);
	if (cmdarg && is_builtin(cmdarg[0]))
		exec_builtin(cmdarg, mini);
	else if (cmdarg)
		exec_bin(cmdarg, mini);
	if (!is_builtin(cmdarg[0]))
		ft_seterrno(errno);
	ft_memdel(cmdarg);
	ft_close(mini->pipin);
	ft_close(mini->pipout);
	mini->pipin = -1;
	mini->pipout = -1;
	mini->exec = 0;
}
