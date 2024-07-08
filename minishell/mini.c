/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:33:33 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/08 21:01:53 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini(t_b *mini)
{
	t_cmd	*start;

	printf("%s\n", mini->rd);
	start = get_start(mini->rd);
	while (start)
	{
		printf("cmd: %s (%d)\n", start->str, start->type);
		start = start->next;
	}
}

t_cmd	*next_token(char *line, int *i)
{
	t_cmd	*cmd;
	int		j;
	char	quote;

	j = 0;
	quote = ' ';
	if (!(cmd = malloc(sizeof(t_cmd)))
	|| !(cmd->str = malloc(sizeof(char) * next_alloc(line, i))))
		return (NULL);
	while (line[*i] && (line[*i] != ' ' || quote != ' '))
	{
		if (quote == ' ' && (line[*i] == '\'' || line[*i] == '\"'))
			quote = line[(*i)++];
		else if (quote != ' ' && line[*i] == quote && (*i)++)
			quote = ' ';
		else
			cmd->str[j++] = line[(*i)++];
	}
	cmd->str[j] = '\0';
	return (cmd);
}

t_cmd	*get_start(char *rd)
{
	t_cmd	*prev;
	t_cmd	*next;
	int		i;

	prev = NULL;
	next = NULL;
	i = 0;
	while (rd[i])
	{
		next = next_token(rd, &i);
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