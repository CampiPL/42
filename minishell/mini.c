/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:33:33 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/13 11:40:17 by ubuntu           ###   ########.fr       */
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
	{
		// printf("in cmd rd[%i]: %c\n", *i, rd[*i]);
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
		// printf("in get start rd[%i]: %c\n", i, rd[i]);
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

void	mini(t_b *mini)
{
	t_cmd	*start;
	t_cmd	*cmd;
	int		status;
	// t_cmd	*token;

	// printf("Line: %s\n", mini->rd);
	start = get_start(mini->rd);
	// token = start;
	// while (token)
	// {
	// 	printf("Start tokens: %s (%i)\n", token->str, token->type);
	// 	token = token->next;
	// }
	cmd = next_run(start);
	// token = cmd;
	// while (token)
	// {
	// 	printf("Cmd tokens: %s (%i)\n", token->str, token->type);
	// 	token = token->next;
	// }
	reset_fds(mini);
	mini->in = dup(0);
	mini->out = dup(1);
	while (cmd)
	{
		mini->exec = 1;
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
