/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:03:06 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/13 21:20:42 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*next_run(t_cmd *token)
{
	while (token && token->type != CMD)
	{
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
