/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:33:33 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/12 20:57:47 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*next_cmd(char *rd, int *i)
{
	t_cmd	*cmd;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	cmd = malloc(sizeof(t_cmd));
	cmd->str = malloc(sizeof(char) * next_alloc(rd, i));
	if (!cmd || !cmd->str)
		return (NULL);
	while (rd[*i] && (rd[*i] != ' ' || c != ' '))
	{
		if (c == ' ' && (rd[*i] == '\'' || rd[*i] == '\"'))
			c = rd[(*i)++];
		else if (c != ' ' && rd[(*i)++] == c)
			c = ' ';
		else if (rd[*i] == '\\' && (*i)++)
			cmd->str[j++] = rd[(*i)++];
		else
			cmd->str[j++] = rd[(*i)++];
	}
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
		i++;
	}
	if (next)
		next->next = NULL;
	while (next && next->prev)
		next = next->prev;
	return (next);
}

void	mini(t_b *mini)
{
	t_cmd	*start;
	t_cmd	*cmd;
	int		status;

	// printf("Line: %s\n", mini->rd);
	start = get_start(mini->rd);
	cmd = next_run(start);
	// while (cmd)
	// {
	// 	printf("Cmd tokens: %s\n", cmd->str);
	// 	cmd = cmd->next;
	// }
	cmd = next_run(start);
	reset_fds(mini);
	mini->in = dup(0);
	mini->out = dup(1);
	while (cmd)
	{
		mini->charge = 1;
		mini->parent = 1;
		redir_and_exec(mini, cmd);
		// printf("Pora to konczyc\n");
		reset_std(mini);
		close_fds(mini);
		reset_fds(mini);
		waitpid(-1, &status, 0);
		if (mini->parent == 0)
		{
			// printf("lol\n");
			free_cmd(start);
			exit(0);
		}
		cmd = next_run(cmd->next);
	}
	free_cmd(start);
}
