/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirexec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:38 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/14 13:24:19 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	minipipe(t_b *mini)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		ft_close(pipefd[1]);
		dup2(pipefd[0], 0);
		mini->pipin = pipefd[0];
		mini->parent = 0;
		return (2);
	}
	else
	{
		ft_close(pipefd[0]);
		dup2(pipefd[1], 1);
		mini->pipout = pipefd[1];
		return (1);
	}
}

static t_cmd	*next_sep(t_cmd *cmd)
{
	while (cmd && cmd->type < TRUNC)
		cmd = cmd->next;
	return (cmd);
}

static t_cmd	*prev_sep(t_cmd *cmd)
{
	while (cmd && cmd->type < TRUNC)
		cmd = cmd->prev;
	return (cmd);
}

void	redir_and_exec(t_b *mini, t_cmd *cmd)
{
	t_cmd	*prev;
	t_cmd	*next;
	int		pipe;

	prev = prev_sep(cmd);
	next = next_sep(cmd);
	pipe = 0;
	if (is_type(prev, TRUNC))
		redir(mini, cmd, TRUNC);
	else if (is_type(prev, APPEND))
		redir(mini, cmd, APPEND);
	else if (is_type(prev, INPUT))
		input(mini, cmd);
	else if (is_type(prev, HEREDOC))
		heredoc(mini, cmd);
	else if (is_type(prev, PIPE))
		pipe = minipipe(mini);
	if (next && pipe != 1)
		redir_and_exec(mini, next->next);
	if ((is_type(prev, PIPE) || !prev)
		&& pipe != 1)
		exec_cmd(mini, cmd);
}
