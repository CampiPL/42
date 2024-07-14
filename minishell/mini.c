/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:33:33 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/14 13:55:28 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*next_cmd(char *rd, int *i)
{
	t_cmd	*cmd;
	int		j;

	j = 0;
	cmd = malloc(sizeof(t_cmd));
	cmd->str = malloc(sizeof(char) * next_alloc(rd, i));
	if (!cmd || !cmd->str)
		return (NULL);
	while (rd[*i] && rd[*i] != ' ')
		cmd->str[j++] = rd[(*i)++];
	cmd->str[j] = '\0';
	return (cmd);
}

static t_cmd	*get_start(char *rd)
{
	t_cmd	*prev;
	t_cmd	*next;
	int		i;

	prev = NULL;
	next = NULL;
	i = 0;
	while (rd[i])
	{
		next = next_cmd(rd, &i);
		next->prev = prev;
		if (prev)
			prev->next = next;
		prev = next;
		type_arg(next);
		if (rd[i] == ' ')
			i++;
	}
	if (next)
		next->next = NULL;
	while (next && next->prev)
		next = next->prev;
	return (next);
}

static void	mini_run_commands(t_b *mini, t_cmd *cmd)
{
	mini->exec = 1;
	mini->parent = 1;
	redir_and_exec(mini, cmd);
	reset_std(mini);
	close_fds(mini);
	reset_fds(mini);
}

void	mini(t_b *mini)
{
	t_cmd	*start;
	t_cmd	*cmd;
	int		status;

	start = get_start(mini->rd);
	cmd = next_run(start);
	reset_fds(mini);
	mini->in = dup(0);
	mini->out = dup(1);
	while (cmd)
	{
		mini_run_commands(mini, cmd);
		waitpid(-1, &status, 0);
		if (mini->parent == 0)
		{
			ft_freebulk("sllffff", mini->env, mini->secret_env, mini->rd,
				mini->in, mini->out, mini->hist, mini->err);
			free_cmd(start);
			exit(0);
		}
		cmd = next_run(cmd->next);
	}
	ft_freebulk("ff", mini->in, mini->out);
	free_cmd(start);
}
