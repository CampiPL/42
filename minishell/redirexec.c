/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirexec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:38 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/10 14:32:46 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	(void) mini;
	printf("cmd: %s\n", cmd->str);
	prev = prev_sep(cmd);
	next = next_sep(cmd);
	if (prev)
		printf("prev: %s\n", prev->str);
	if (next)
		printf("next: %s\n", next->str);
	pipe = 0;
	/*
	if (is_type(prev, TRUNC))
		redir(mini, cmd, TRUNC);
	else if (is_type(prev, APPEND))
		redir(mini, cmd, APPEND);
	else if (is_type(prev, INPUT))
		input(mini, cmd);
	else if (is_type(prev, PIPE))
		pipe = minipipe(mini);
	if (next && pipe != 1)
		redir_and_exec(mini, next->next);
	*/
	if ((is_type(prev, PIPE) || !prev)
		&& pipe != 1)
		exec_cmd(mini, cmd);
}
