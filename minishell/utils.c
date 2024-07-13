/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:03:06 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/13 11:39:10 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*next_run(t_cmd *token)
{
	while (token && token->type != CMD)
	{
		// printf("Checking token: %s\n", token->str);
		token = token->next;
		if (token && token->type == CMD && token->prev == NULL)
			;
		else if (token && token->type == CMD)
			token = token->next;
	}
	return (token);
}

int	next_alloc(char *line, int *i)
{
	int		j;

	j = 0;
	while (line[*i + j] && line[*i + j] != ' ')
		j++;
	return (j + 1);
}

void	sig_init(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pid = 0;
	g_sig.exit_status = 0;
}
