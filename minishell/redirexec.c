/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirexec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:34:38 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/09 17:36:39 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_and_exec(t_b *mini, t_cmd *cmd)
{
	t_cmd	*prev;
	t_cmd	*next;
	int		pipe;

	prev = prev_sep(cmd, NOSKIP);
	next = next_sep(cmd, NOSKIP);
	/*
	if (prev)
		printf("prev: %s\n", prev->str);
	if (next)
		printf("next: %s\n", next->str);
	*/
	pipe = 0;
	if (is_type(prev, TRUNC))
		redir(mini, cmd, TRUNC);
	else if (is_type(prev, APPEND))
		redir(mini, cmd, APPEND);
	else if (is_type(prev, INPUT))
		input(mini, cmd);
	else if (is_type(prev, PIPE))
		pipe = minipipe(mini);
	if (next && is_type(next, END) == 0 && pipe != 1)
		redir_and_exec(mini, next->next);
	if ((is_type(prev, END) || is_type(prev, PIPE) || !prev)
		&& pipe != 1 && mini->no_exec == 0)
		exec_cmd(mini, cmd);
}
