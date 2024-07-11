/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:33:33 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/11 20:57:08 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*next_cmd(char *rd, int *i)
{
	t_cmd	*cmd;
	int		j;
	char	quote;

	j = 0;
	quote = ' ';
	cmd = malloc(sizeof(t_cmd));
	cmd->str = malloc(sizeof(char) * next_alloc(rd, i));
	if (!cmd || !cmd->str)
		return (NULL);
	while (rd[*i] && (rd[*i] != ' ' || quote != ' '))
	{
		if (quote == ' ' && (rd[*i] == '\'' || rd[*i] == '\"'))
			quote = rd[(*i)++];
		else if (quote != ' ' && rd[*i] == quote && (*i)++)
			quote = ' ';
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
	(void) rd;
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

	printf("%s\n", mini->rd);
	start = get_start(mini->rd);
	cmd = next_run(start);
	while (cmd)
	{
		printf("cmd: %s (%d)\n", cmd->str, cmd->type);
		redir_and_exec(mini, cmd);
		cmd = next_run(cmd->next);
	}
	free_cmd(start);
}
